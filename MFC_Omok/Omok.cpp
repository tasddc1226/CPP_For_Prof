
// Omok.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "Omok.h"
#include "OmokDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COmokApp

BEGIN_MESSAGE_MAP(COmokApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// COmokApp ����

COmokApp::COmokApp()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ COmokApp ��ü�Դϴ�.

COmokApp theApp;


// COmokApp �ʱ�ȭ

BOOL COmokApp::InitInstance()
{
	CWinApp::InitInstance();

	COmokDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	
	return FALSE;
}



