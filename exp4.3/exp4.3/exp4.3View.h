
// exp4.3View.h : Cexp43View ��Ľӿ�
//

#pragma once


class Cexp43View : public CView
{
protected: // �������л�����
	Cexp43View();
	DECLARE_DYNCREATE(Cexp43View)

// ����
public:
	Cexp43Doc* GetDocument() const;

// ����
public:
	int m_Dragging=0;
	CPoint m_PointOld;
	CPoint m_PointOrigin;
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
	virtual ~Cexp43View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawline();
	afx_msg void OnDrawrec();
	afx_msg void OnDraworal();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp4.3View.cpp �еĵ��԰汾
inline Cexp43Doc* Cexp43View::GetDocument() const
   { return reinterpret_cast<Cexp43Doc*>(m_pDocument); }
#endif

