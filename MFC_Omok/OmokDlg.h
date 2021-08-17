
// OmokDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#define MAX_X_COUNT 11
#define MAX_Y_COUNT 11

#define LINE_INTERVAL 40 // �簢�� ũ��

// COmokDlg ��ȭ ����
class COmokDlg : public CDialogEx
{
// �����Դϴ�.
public:
	COmokDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	CBrush m_white_brush;
	CBrush m_black_brush;
	int m_step_count = 0; // ���� ����
	char m_dol_pos[MAX_X_COUNT][MAX_Y_COUNT]; // 0 : �� ����, 1 : black, 2 : white

	enum player {BLACK = 1, WHITE = 2};
	int nowPlayer = player::BLACK;

	BOOL isWin() {
		printf("player : %d win �Լ� ����!\n", nowPlayer);
		// | �¸� ����
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

		// �� �¸� ����
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

		// / �¸� ����
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

		// \ �¸� ����
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

	
	

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OMOK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CListBox m_console;
};
