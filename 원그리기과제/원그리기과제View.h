
// 원그리기과제View.h: C원그리기과제View 클래스의 인터페이스
//

#pragma once


class C원그리기과제View : public CView
{
protected: // serialization에서만 만들어집니다.
	C원그리기과제View() noexcept;
	DECLARE_DYNCREATE(C원그리기과제View)

	// 특성입니다.
public:
	C원그리기과제Doc* GetDocument() const;

	// 작업입니다.
public:

	// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// 구현입니다.
public:
	virtual ~C원그리기과제View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint m_pt1;
	CPoint m_pt2;
	int Length(CPoint m_pt1, CPoint m_pt2);
	int m_Radius;
	COLORREF m_brushColor;
};

#ifndef _DEBUG  // 원그리기과제View.cpp의 디버그 버전
inline C원그리기과제Doc* C원그리기과제View::GetDocument() const
   { return reinterpret_cast<C원그리기과제Doc*>(m_pDocument); }
#endif

