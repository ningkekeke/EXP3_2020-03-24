
// exp4.3Doc.h : Cexp43Doc 类的接口
//


#pragma once


class Cexp43Doc : public CDocument
{
protected: // 仅从序列化创建
	Cexp43Doc();
	DECLARE_DYNCREATE(Cexp43Doc)

// 特性
public:
	int flag1 = 0, flag2 = 0, flag3 = 0;
	BOOL m_startRect;   //绘制矩形框标志
	CPoint m_startPoint; 
	CPoint m_OldPoint;
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~Cexp43Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
