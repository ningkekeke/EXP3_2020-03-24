
// exp4.1View.cpp : Cexp41View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp4.1.h"
#endif

#include "exp4.1Doc.h"
#include "exp4.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp41View

IMPLEMENT_DYNCREATE(Cexp41View, CView)

BEGIN_MESSAGE_MAP(Cexp41View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_NameShow, &Cexp41View::NameShow)
END_MESSAGE_MAP()

// Cexp41View 构造/析构

Cexp41View::Cexp41View()
{
	// TODO: 在此处添加构造代码

}

Cexp41View::~Cexp41View()
{
}

BOOL Cexp41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp41View 绘制

void Cexp41View::OnDraw(CDC* /*pDC*/)
{
	Cexp41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp41View 打印

BOOL Cexp41View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp41View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp41View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp41View 诊断

#ifdef _DEBUG
void Cexp41View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp41Doc* Cexp41View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp41Doc)));
	return (Cexp41Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp41View 消息处理程序

void Cexp41View::NameShow()
{
	// TODO: 在此添加命令处理程序代码
	CString S;
	S.Format(_T("宁可"));
	CClientDC dc(this);
	dc.TextOutW(200, 200, S);
}
