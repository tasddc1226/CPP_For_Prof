
// OmokDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Omok.h"
#include "OmokDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COmokDlg ��ȭ ����

COmokDlg::COmokDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OMOK_DIALOG, pParent), m_white_brush(RGB(255,255,255)), m_black_brush(RGB(0,0,0))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	// �ٵ��� �ʱ�ȭ
	for (int y = 0; y < MAX_Y_COUNT; y++) {
		for (int x = 0; x < MAX_X_COUNT; x++) {
			m_dol_pos[y][x] = 0; // 0�̸� �� ���� 1�̸� black, 2�� white
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


// COmokDlg �޽��� ó����

BOOL COmokDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_console.AddString(_T("������ �����մϴ�."));

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void COmokDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		for (int y = 1; y < MAX_Y_COUNT - 1; y++) { // y���� ���� ������ �ִ�.
			for (int x = 1; x < MAX_X_COUNT - 1; x++) {
				dc.Rectangle(x*LINE_INTERVAL, y*LINE_INTERVAL,
					x*LINE_INTERVAL + LINE_INTERVAL +1, y*LINE_INTERVAL + LINE_INTERVAL+1);
			}
		}
		CBrush *p_old_brush;

		
		// ������ �ٵϵ��� �ٽ� �׸��� �κ�
		// ��ȿȭ ������ ���� WM_PAINT �޽����� �߻��Ͽ�
		// OnPaint �Լ��� ����ǹǷ� �����س��� ��ǥ�������� �ٵϵ��� ����
		// �̿��Ͽ� �ٽ� �׷��ش�.
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
		printf("���� ���ʴ� %d player �Դϴ�.\n", nowPlayer);

		// m_console.InsertString(m_step_count, _T("�ٵ��� �ʱ�ȭ �Ϸ�"));
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR COmokDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COmokDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);

	// ���� �����ϴ� ������ �� ����
	// point.x, point.y => ����ڰ� Ŭ���� ��ǥ
	// x, y�� LINE_INTERVAL�� ������ �ٵ����� ��ǥ���� ��. (�������� ������ ����)
	int x = point.x / LINE_INTERVAL;
	int y = point.y / LINE_INTERVAL;

	if (point.x % LINE_INTERVAL > LINE_INTERVAL / 2) x++;
	if (point.y % LINE_INTERVAL > LINE_INTERVAL / 2) y++;

	// ��ȿ ���� ����
	if (x > 0 && y > 0 && x <= MAX_X_COUNT && y <= MAX_Y_COUNT) {
		// ��ȿ ���� ���� �����ϰ�, �ش� ��ǥ�� ���� ���ٸ� ����
		if (m_dol_pos[y - 1][x - 1] == 0) { 
			// ����ϴ� brush�� �ּҸ� �����ϱ� ���� ������
			CBrush *p_old_brush; 

			// 0���� �����Ƿ� else�� ���� ����
			if (m_step_count % 2) { 
				m_dol_pos[y - 1][x - 1] = 2; // ��
				p_old_brush = dc.SelectObject(&m_white_brush);
				printf("pos : %d, %d\n", x, y);
			}
			else {
				m_dol_pos[y - 1][x - 1] = 1; // ���� ��
				p_old_brush = dc.SelectObject(&m_black_brush);
				printf("pos : %d, %d\n", x, y);
				
			}

			x = x*LINE_INTERVAL;
			y = y*LINE_INTERVAL;

			dc.Ellipse(x - LINE_INTERVAL / 2, y - LINE_INTERVAL / 2, // ���� ������
				x + LINE_INTERVAL / 2, y + LINE_INTERVAL / 2); // ���� ��������

			// �����ʹ� ��ü�� �ּҰ��̹Ƿ� &�� ������ ����.
			dc.SelectObject(p_old_brush);
			m_step_count++;

			// �¸� ���� Ȯ��
			if (isWin()) {
				if (nowPlayer == BLACK)
					m_console.AddString(_T("�� �÷��̾� �¸�!"));
				else
					m_console.AddString(_T("�� �÷��̾� �¸�!"));
			}
			else {
				if (nowPlayer == 1) {
					nowPlayer = player::WHITE;
					m_console.AddString(_T("�� �÷��̾� �����Դϴ�."));
				}
				else {
					nowPlayer = player::BLACK;
					m_console.AddString(_T("�� �÷��̾� �����Դϴ�."));
				}
				// printf("���� ���ʴ� %d player �Դϴ�.\n", nowPlayer);
				// printf("return false!\n");
			}

		}
	}
	else {
		AfxMessageBox(_T("�� ������ ���� �� ����!"), MB_ICONSTOP);
	}

	
	CDialogEx::OnLButtonDown(nFlags, point);
}


