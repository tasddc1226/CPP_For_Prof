// ConectSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SocketClient.h"
#include "ConnectSocket.h"
#include "SocketClientDlg.h"

// CConectSocket

CConectSocket::CConectSocket()
{
}

CConectSocket::~CConectSocket()
{
}


// CConectSocket 멤버 함수


void CConectSocket::OnClose(int nErrorCode)
{
	ShutDown();
	Close();

	CSocket::OnClose(nErrorCode);

	AfxMessageBox(_T("ERROR:Disconnected from server!"));
	::PostQuitMessage(0);
}


void CConectSocket::OnReceive(int nErrorCode)
{
	TCHAR szBuffer[1024];
	::ZeroMemory(szBuffer, sizeof(szBuffer));

	if (Receive(szBuffer, sizeof(szBuffer)) > 0) {
		CSocketClientDlg* pMain = (CSocketClientDlg*)AfxGetMainWnd();
		pMain->m_List.AddString(szBuffer);
		pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1);
	}
	CSocket::OnReceive(nErrorCode);
}
