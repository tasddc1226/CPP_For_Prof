#pragma once

// CConectSocket 명령 대상입니다.

class CConectSocket : public CSocket
{
public:
	CConectSocket();
	virtual ~CConectSocket();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};


