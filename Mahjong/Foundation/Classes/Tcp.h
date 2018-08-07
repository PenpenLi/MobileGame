#pragma once
#ifdef WIN32
#include <WinSock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#endif

#include <errno.h>

class Tcp
{
public:
	Tcp();
	~Tcp();
	enum{
		SHUT_RECEIVE,
		SHUT_SEND,
		SHUT_BOTH,
	};
	bool Create();
	void Close();

	bool SetBlocking();
	bool SetNonblocking();

	int Connect(char* apAddr, int aPort);
	
	int Send(char* apBuffer, int aLength);
	int Recv(char* apBuffer, int aLength);
	int SendFull(char *apBuffer, int aLength);
	int RecvFull(char *apbuffer, int aLength);
	int GetSocket(){ return m_Socket; };
	
private:
	int m_Socket;
};

