
// exp4.1View.cpp : Cexp41View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_NameShow, &Cexp41View::NameShow)
END_MESSAGE_MAP()

// Cexp41View ����/����

Cexp41View::Cexp41View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp41View::~Cexp41View()
{
}

BOOL Cexp41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp41View ����

void Cexp41View::OnDraw(CDC* /*pDC*/)
{
	Cexp41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp41View ��ӡ

BOOL Cexp41View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp41View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp41View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp41View ���

#ifdef _DEBUG
void Cexp41View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp41Doc* Cexp41View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp41Doc)));
	return (Cexp41Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp41View ��Ϣ�������

void Cexp41View::NameShow()
{
	// TODO: �ڴ���������������
	CString S;
	S.Format(_T("����"));
	CClientDC dc(this);
	dc.TextOutW(200, 200, S);
}
