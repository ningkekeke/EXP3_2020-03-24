
// exp4.1View.h : Cexp41View ��Ľӿ�
//

#pragma once


class Cexp41View : public CView
{
protected: // �������л�����
	Cexp41View();
	DECLARE_DYNCREATE(Cexp41View)

// ����
public:
	Cexp41Doc* GetDocument() const;

// ����
public:

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
	virtual ~Cexp41View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void NameShow();
};

#ifndef _DEBUG  // exp4.1View.cpp �еĵ��԰汾
inline Cexp41Doc* Cexp41View::GetDocument() const
   { return reinterpret_cast<Cexp41Doc*>(m_pDocument); }
#endif

