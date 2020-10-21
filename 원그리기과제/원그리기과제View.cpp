
// 원그리기과제View.cpp: C원그리기과제View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "원그리기과제.h"
#endif

#include "원그리기과제Doc.h"
#include "원그리기과제View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C원그리기과제View

IMPLEMENT_DYNCREATE(C원그리기과제View, CView)

BEGIN_MESSAGE_MAP(C원그리기과제View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// C원그리기과제View 생성/소멸

C원그리기과제View::C원그리기과제View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C원그리기과제View::~C원그리기과제View()
{
}

BOOL C원그리기과제View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// C원그리기과제View 그리기

void C원그리기과제View::OnDraw(CDC* pDC)
{
	C원그리기과제Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CBrush brush;
	brush.CreateSolidBrush(m_brushColor);
	pDC->SelectObject(&brush);
	pDC->Ellipse(m_pt1.x-m_Radius,m_pt1.y-m_Radius,m_pt1.x+m_Radius,m_pt1.y+m_Radius);

}


// C원그리기과제View 인쇄

BOOL C원그리기과제View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void C원그리기과제View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void C원그리기과제View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// C원그리기과제View 진단

#ifdef _DEBUG
void C원그리기과제View::AssertValid() const
{
	CView::AssertValid();
}

void C원그리기과제View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C원그리기과제Doc* C원그리기과제View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C원그리기과제Doc)));
	return (C원그리기과제Doc*)m_pDocument;
}
#endif //_DEBUG


// C원그리기과제View 메시지 처리기


void C원그리기과제View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_pt1 = point;

	CView::OnLButtonDown(nFlags, point);
}

void C원그리기과제View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_pt2 = point;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}

void C원그리기과제View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags & MK_LBUTTON) {
		m_pt2 = point;
		m_Radius = Length(m_pt1, m_pt2);
		m_brushColor = RGB(m_Radius%255, 0, 0);
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


int C원그리기과제View::Length(CPoint m_pt1, CPoint m_pt2)
{
	// TODO: 여기에 구현 코드 추가.
    return (int)(sqrt((m_pt2.x - m_pt1.x) * (m_pt2.x - m_pt1.x) + (m_pt2.y - m_pt1.y) * (m_pt2.y - m_pt1.y)));
}



