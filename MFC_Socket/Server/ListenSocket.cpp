// ListenSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SocketServer.h"
#include "ListenSocket.h"
#include "ClientSocket.h"
#include "SocketServerDlg.h"


// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}


// CListenSocket 멤버 함수
// 1. 서버-클라이언트의 연결 담당
void CListenSocket::OnAccept(int nErrorCode) { 
	CClientSocket* pClient = new CClientSocket;
	CString str;

	if (Accept(*pClient)) { // 클라이언트 접속 요청이 오면 서버-클라이언트를 연결시켜준다
		pClient->SetListenSocket(this);
		m_ptrClientSocketList.AddTail(pClient);

		CSocketServerDlg* pMain = (CSocketServerDlg*)AfxGetMainWnd(); // CSocketServerDlg의 핸들을 가져옴
		str.Format(_T("Client (%d)"), (int)m_ptrClientSocketList.Find(pClient)); // 클라이언트 번호(POSITION 값)
		pMain->clientList->AddString(str); // 클라이언트가 접속할때마다 리스트에 클라이언트 이름 추가

	}
	else {
		delete pClient;
		AfxMessageBox(_T("ERROR : Failed can't accept new Client!"));
	}

	CAsyncSocket::OnAccept(nErrorCode);
}

// 2. 클라이언트 연결 종료 함수
void CListenSocket::CloseClientSocket(CSocket* pClient)
{
	POSITION pos;
	pos = m_ptrClientSocketList.Find(pClient);

	if (pos != NULL) {
		if (pClient != NULL) {
			// 클라이언트 연결중지후 종료
			pClient->ShutDown();
			pClient->Close();
		}

		CSocketServerDlg* pMain = (CSocketServerDlg*)AfxGetMainWnd();
		CString str1, str2;
		UINT indx = 0, posNum;
		pMain->clientList->SetCurSel(0);
		// 접속 종료되는 클라이언트 찾기
		while (indx < pMain->clientList->GetCount()) {
			posNum = (int)m_ptrClientSocketList.Find(pClient);
			pMain->clientList->GetText(indx, str1);
			str2.Format(_T("%d"), posNum);
			// 소켓리스트, 클라이언트리스트를 비교해서 같은 클라이언트 번호(POSITION 값) 있으면 리스트에서 삭제
			if (str1.Find(str2) != -1) {
				AfxMessageBox(str1 + str2 + " has disconnected!");
				pMain->clientList->DeleteString(indx);
				break;
			}
			indx++;
		}

		m_ptrClientSocketList.RemoveAt(pos);
		delete pClient;
	}
}

// 3. 클라이언트 메시지를 다른 클라이언트에게 전송하는 함수
void CListenSocket::SendAllMessage(TCHAR* pszMessage)
{
	POSITION pos;
	pos = m_ptrClientSocketList.GetHeadPosition();
	CClientSocket* pClient = NULL;

	while (pos != NULL) {
		pClient = (CClientSocket*)m_ptrClientSocketList.GetNext(pos);
		if (pClient != NULL) {
			// Send함수의 두번째 인자는 메모리의 크기인데 유니코드를 사용하고 있으므로 *2를 한 크기가 된다.
			// 이 함수는 전송한 데이터의 길이를 반환한다.
			int checkLenOfData = pClient->Send(pszMessage, lstrlen(pszMessage) * 2);
			if (checkLenOfData != lstrlen(pszMessage) * 2) {
				AfxMessageBox(_T("일부 데이터가 정상적을 전송되지 못했습니다!"));
			}
		}
	}
}