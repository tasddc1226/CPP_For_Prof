
// OmokDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Omok.h"
#include "OmokDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COmokDlg 대화 상자

COmokDlg::COmokDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OMOK_DIALOG, pParent), m_white_brush(RGB(255,255,255)), m_black_brush(RGB(0,0,0))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	// 바둑판 초기화
	for (int y = 0; y < MAX_Y_COUNT; y++) {
		for (int x = 0; x < MAX_X_COUNT; x++) {
			m_dol_pos[y][x] = 0; // 0이면 돌 없음 1이면 black, 2면 white
		}
	}
}

void COmokDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_console);
}

BEGIN_MESSAGE_MAP(COmokDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// COmokDlg 메시지 처리기

BOOL COmokDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_console.AddString(_T("오목을 시작합니다."));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void COmokDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		for (int y = 1; y < MAX_Y_COUNT - 1; y++) { // y부터 쓰는 관습이 있다.
			for (int x = 1; x < MAX_X_COUNT - 1; x++) {
				dc.Rectangle(x*LINE_INTERVAL, y*LINE_INTERVAL,
					x*LINE_INTERVAL + LINE_INTERVAL +1, y*LINE_INTERVAL + LINE_INTERVAL+1);
			}
		}
		CBrush *p_old_brush;

		
		// 지워진 바둑돌을 다시 그리는 부분
		// 무효화 영역에 들어가면 WM_PAINT 메시지가 발생하여
		// OnPaint 함수가 실행되므로 저장해놓은 좌표값에대한 바둑돌의 값을
		// 이용하여 다시 그려준다.
		for (int y = 1; y <= MAX_Y_COUNT; y++) {
			for (int x = 1; x <= MAX_X_COUNT; x++) {
				if (m_dol_pos[y - 1][x - 1]) {
					if (m_dol_pos[y - 1][x - 1] == 1) {
						p_old_brush = dc.SelectObject(&m_black_brush);
					} else {
						p_old_brush = dc.SelectObject(&m_white_brush);
					}
					dc.Ellipse(x*LINE_INTERVAL - LINE_INTERVAL / 2, y*LINE_INTERVAL - LINE_INTERVAL / 2,
						x*LINE_INTERVAL + LINE_INTERVAL + 1 - LINE_INTERVAL / 2,
						y*LINE_INTERVAL + LINE_INTERVAL + 1 - LINE_INTERVAL / 2);
					dc.SelectObject(p_old_brush);
				}
			}
		}
		CDialogEx::OnPaint();
		printf("현재 차례는 %d player 입니다.\n", nowPlayer);

		// m_console.InsertString(m_step_count, _T("바둑판 초기화 완료"));
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR COmokDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COmokDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);

	// 점이 교차하는 지점에 돌 놓기
	// point.x, point.y => 사용자가 클릭한 좌표
	// x, y는 LINE_INTERVAL로 나누어 바둑판의 좌표값이 됨. (나머지는 버리기 때문)
	int x = point.x / LINE_INTERVAL;
	int y = point.y / LINE_INTERVAL;

	if (point.x % LINE_INTERVAL > LINE_INTERVAL / 2) x++;
	if (point.y % LINE_INTERVAL > LINE_INTERVAL / 2) y++;

	// 유효 범위 지정
	if (x > 0 && y > 0 && x <= MAX_X_COUNT && y <= MAX_Y_COUNT) {
		// 유효 범위 내에 존재하고, 해당 좌표에 돌이 없다면 실행
		if (m_dol_pos[y - 1][x - 1] == 0) { 
			// 사용하던 brush의 주소를 저장하기 위한 포인터
			CBrush *p_old_brush; 

			// 0부터 나오므로 else문 부터 실행
			if (m_step_count % 2) { 
				m_dol_pos[y - 1][x - 1] = 2; // 흰돌
				p_old_brush = dc.SelectObject(&m_white_brush);
				printf("pos : %d, %d\n", x, y);
			}
			else {
				m_dol_pos[y - 1][x - 1] = 1; // 검은 돌
				p_old_brush = dc.SelectObject(&m_black_brush);
				printf("pos : %d, %d\n", x, y);
				
			}

			x = x*LINE_INTERVAL;
			y = y*LINE_INTERVAL;

			dc.Ellipse(x - LINE_INTERVAL / 2, y - LINE_INTERVAL / 2, // 원의 시작점
				x + LINE_INTERVAL / 2, y + LINE_INTERVAL / 2); // 원의 끝나는점

			// 포인터는 자체가 주소값이므로 &를 붙이지 않음.
			dc.SelectObject(p_old_brush);
			m_step_count++;

			// 승리 조건 확인
			if (isWin()) {
				if (nowPlayer == BLACK)
					m_console.AddString(_T("흑 플레이어 승리!"));
				else
					m_console.AddString(_T("백 플레이어 승리!"));
			}
			else {
				if (nowPlayer == 1) {
					nowPlayer = player::WHITE;
					m_console.AddString(_T("백 플레이어 차례입니다."));
				}
				else {
					nowPlayer = player::BLACK;
					m_console.AddString(_T("흑 플레이어 차례입니다."));
				}
				// printf("현재 차례는 %d player 입니다.\n", nowPlayer);
				// printf("return false!\n");
			}

		}
	}
	else {
		AfxMessageBox(_T("그 지역은 놓을 수 없음!"), MB_ICONSTOP);
	}

	
	CDialogEx::OnLButtonDown(nFlags, point);
}


