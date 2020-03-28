
// exp4.2View.h : Cexp42View 类的接口
//

#pragma once


class Cexp42View : public CView
{
protected: // 仅从序列化创建
	Cexp42View();
	DECLARE_DYNCREATE(Cexp42View)

// 特性
public:
	Cexp42Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;
	BITMAP BM;
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
	virtual ~Cexp42View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp4.2View.cpp 中的调试版本
inline Cexp42Doc* Cexp42View::GetDocument() const
   { return reinterpret_cast<Cexp42Doc*>(m_pDocument); }
#endif

