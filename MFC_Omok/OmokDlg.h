
// OmokDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#define MAX_X_COUNT 11
#define MAX_Y_COUNT 11

#define LINE_INTERVAL 40 // 사각형 크기

// COmokDlg 대화 상자
class COmokDlg : public CDialogEx
{
// 생성입니다.
public:
	COmokDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	CBrush m_white_brush;
	CBrush m_black_brush;
	int m_step_count = 0; // 놓을 순서
	char m_dol_pos[MAX_X_COUNT][MAX_Y_COUNT]; // 0 : 돌 없음, 1 : black, 2 : white

	enum player {BLACK = 1, WHITE = 2};
	int nowPlayer = player::BLACK;

	BOOL isWin() {
		printf("player : %d win 함수 실행!\n", nowPlayer);
		// | 승리 조건
		for (int i = 0; i < MAX_Y_COUNT - 4; i++) {
			for (int j = 0; j < MAX_X_COUNT; j++) {
				if (m_dol_pos[i][j] == nowPlayer
					&& m_dol_pos[i + 1][j] == nowPlayer
					&& m_dol_pos[i + 2][j] == nowPlayer
					&& m_dol_pos[i + 3][j] == nowPlayer
					&& m_dol_pos[i + 4][j] == nowPlayer) {
					return TRUE;
				}
			}
		}

		// ㅡ 승리 조건
		for (int j = 0; j < MAX_Y_COUNT - 4; j++) {
			for (int i = 0; i < MAX_X_COUNT; i++) {
				if (m_dol_pos[i][j] == nowPlayer
					&& m_dol_pos[i][j + 1] == nowPlayer
					&&  m_dol_pos[i][j + 2] == nowPlayer
					&&  m_dol_pos[i][j + 3] == nowPlayer
					&&  m_dol_pos[i][j + 4] == nowPlayer) {
					return TRUE;
				}
			}
		}

		// / 승리 조건
		for (int i = 0; i < MAX_X_COUNT - 4; i++) {
			for (int j = 0; j < MAX_Y_COUNT - 4; j++) {
				if (m_dol_pos[MAX_X_COUNT - i - 1][j] == nowPlayer
					&& m_dol_pos[MAX_X_COUNT - i - 2][j + 1] == nowPlayer
					&&  m_dol_pos[MAX_X_COUNT - i - 3][j + 2] == nowPlayer
					&&  m_dol_pos[MAX_X_COUNT - i - 4][j + 3] == nowPlayer
					&&  m_dol_pos[MAX_X_COUNT - i - 5][j + 4] == nowPlayer) {
					return TRUE;
				}
			}
		}

		// \ 승리 조건
		for (int i = 0; i < MAX_X_COUNT - 4; i++) {
			for (int j = 0; j < MAX_Y_COUNT - 4; j++) {
				if (m_dol_pos[i][j] == nowPlayer
					&& m_dol_pos[i + 1][j + 1] == nowPlayer
					&&  m_dol_pos[i + 2][j + 2] == nowPlayer
					&&  m_dol_pos[i + 3][j + 3] == nowPlayer
					&&  m_dol_pos[i + 4][j + 4] == nowPlayer) {
					return TRUE;
				}
			}
		}

		return FALSE;

	}

	
	

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OMOK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CListBox m_console;
};
