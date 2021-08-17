
// Omok.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
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


// COmokApp 생성

COmokApp::COmokApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 COmokApp 개체입니다.

COmokApp theApp;


// COmokApp 초기화

BOOL COmokApp::InitInstance()
{
	CWinApp::InitInstance();

	COmokDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	
	return FALSE;
}



