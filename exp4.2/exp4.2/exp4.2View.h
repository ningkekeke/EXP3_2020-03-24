
// exp4.2View.h : Cexp42View ��Ľӿ�
//

#pragma once


class Cexp42View : public CView
{
protected: // �������л�����
	Cexp42View();
	DECLARE_DYNCREATE(Cexp42View)

// ����
public:
	Cexp42Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;
	BITMAP BM;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Cexp42View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp4.2View.cpp �еĵ��԰汾
inline Cexp42Doc* Cexp42View::GetDocument() const
   { return reinterpret_cast<Cexp42Doc*>(m_pDocument); }
#endif

