
// exp4.3View.h : Cexp43View 类的接口
//

#pragma once


class Cexp43View : public CView
{
protected: // 仅从序列化创建
	Cexp43View();
	DECLARE_DYNCREATE(Cexp43View)

// 特性
public:
	Cexp43Doc* GetDocument() const;

// 操作
public:
	int m_Dragging=0;
	CPoint m_PointOld;
	CPoint m_PointOrigin;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cexp43View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // exp4.3View.cpp 中的调试版本
inline Cexp43Doc* Cexp43View::GetDocument() const
   { return reinterpret_cast<Cexp43Doc*>(m_pDocument); }
#endif

