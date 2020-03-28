
// exp4.2View.cpp : Cexp42View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp4.2.h"
#endif

#include "exp4.2Doc.h"
#include "exp4.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp42View

IMPLEMENT_DYNCREATE(Cexp42View, CView)

BEGIN_MESSAGE_MAP(Cexp42View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cexp42View 构造/析构

Cexp42View::Cexp42View()
{
	// TODO: 在此处添加构造代码
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

Cexp42View::~Cexp42View()
{
}

BOOL Cexp42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp42View 绘制

void Cexp42View::OnDraw(CDC* pDC)
{
	Cexp42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp42View 打印

BOOL Cexp42View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp42View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp42View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp42View 诊断

#ifdef _DEBUG
void Cexp42View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp42Doc* Cexp42View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp42Doc)));
	return (Cexp42Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp42View 消息处理程序
