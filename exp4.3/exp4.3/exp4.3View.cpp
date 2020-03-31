
// exp4.3View.cpp : Cexp43View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp4.3.h"
#endif

#include "exp4.3Doc.h"
#include "exp4.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp43View

IMPLEMENT_DYNCREATE(Cexp43View, CView)

BEGIN_MESSAGE_MAP(Cexp43View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DrawLine, &Cexp43View::OnDrawline)
	ON_COMMAND(ID_DrawRec, &Cexp43View::OnDrawrec)
	ON_COMMAND(ID_DrawOral, &Cexp43View::OnDraworal)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cexp43View 构造/析构

Cexp43View::Cexp43View()
{
	// TODO: 在此处添加构造代码
	
}

Cexp43View::~Cexp43View()
{
	
}

BOOL Cexp43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp43View 绘制

void Cexp43View::OnDraw(CDC* /*pDC*/)
{
	Cexp43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp43View 打印

BOOL Cexp43View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp43View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp43View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp43View 诊断

#ifdef _DEBUG
void Cexp43View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp43Doc* Cexp43View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp43Doc)));
	return (Cexp43Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp43View 消息处理程序


void Cexp43View::OnDrawline()
{
	// TODO: 在此添加命令处理程序代码
	Cexp43Doc* pDoc = GetDocument();
	pDoc->flag2 = 1;
	pDoc->flag1 = 0;
	pDoc->flag3 = 0;
}


void Cexp43View::OnDrawrec()

{
	// TODO: 在此添加命令处理程序代码
	Cexp43Doc* pDoc = GetDocument();
	pDoc->flag1 = 1;
	pDoc->flag2 = 0;
	pDoc->flag3 = 0;
}


void Cexp43View::OnDraworal()
{
	// TODO: 在此添加命令处理程序代码
	Cexp43Doc* pDoc = GetDocument();
	pDoc->flag3 = 1;
	pDoc->flag1 = 0; 
	pDoc->flag2 = 0;
	
}


void Cexp43View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp43Doc* pDoc = GetDocument();
	if (pDoc->flag1){
		pDoc->m_startRect = TRUE;   //鼠标左键单击，设置可以开始绘制矩形框
		pDoc->m_startPoint = point; //记录开始点
		pDoc->m_OldPoint = point;   //设置老点也为开始点	
	}
	if (pDoc->flag2) {
		m_PointOrigin = point;
		m_PointOld = point;
		m_Dragging = 1;
	}
	if (pDoc->flag3) {
		pDoc->m_startRect = TRUE;   //鼠标左键单击，设置可以开始绘制矩形框
		pDoc->m_startPoint = point; //记录开始点
		pDoc->m_OldPoint = point;   //设置老点也为开始点	
	}
	CView::OnLButtonDown(nFlags, point);
}


void Cexp43View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	Cexp43Doc* pDoc = GetDocument();
	CClientDC ClientDC(this);
	if (pDoc->flag1) {
	ClientDC.Rectangle(CRect(pDoc->m_startPoint, pDoc->m_OldPoint));
	pDoc->m_startRect = FALSE;
	}	 //消隐最后的一个矩形（其原理跟拖动时矩形框绘制原理相同）
	if (pDoc->flag2) {
		if(m_Dragging)
		{
			m_Dragging = 0;
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(m_PointOld);//擦去上一次的临时线
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(point);//绘制固定线
		}
	}
	if (pDoc->flag3) {
		ClientDC.Ellipse(CRect(pDoc->m_startPoint, pDoc->m_OldPoint));
		pDoc->m_startRect = FALSE;
	}
	CView::OnLButtonUp(nFlags, point);
}


void Cexp43View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp43Doc* pDoc = GetDocument();
	CClientDC ClientDC(this);   //获取设备句柄
	ClientDC.SetROP2(R2_NOT);//此为关键
	ClientDC.SelectStockObject(NULL_BRUSH);
	if (pDoc->flag1) {
		if (TRUE == pDoc->m_startRect)   //根据是否有单击判断是否可以画矩形
		{
			ClientDC.Rectangle(CRect(pDoc->m_startPoint, pDoc->m_OldPoint));
			ClientDC.Rectangle(CRect(pDoc->m_startPoint, point));
			pDoc->m_OldPoint = point;
		}
	}
	if (pDoc->flag2) {
		if (m_Dragging)
		{
			ClientDC.SetROP2(R2_NOT);//逆转当前屏幕颜色来画线的绘图方式
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(m_PointOld);
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(point);//绘制这一次的临时线
			m_PointOld = point;
		}
	}
	if (pDoc->flag3) {
		if (TRUE == pDoc->m_startRect)   //根据是否有单击判断是否可以画矩形
		{
			ClientDC.Ellipse(CRect(pDoc->m_startPoint, pDoc->m_OldPoint));
			ClientDC.Ellipse(CRect(pDoc->m_startPoint, point));
			pDoc->m_OldPoint = point;
		}
	}
	CView::OnMouseMove(nFlags, point);
}
