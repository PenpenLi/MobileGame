#include "stdafx.h"
#include "Tcp.h"


Tcp::Tcp()
:m_Socket(-1)
{
}


Tcp::~Tcp()
{
	Close();
}

bool Tcp::Create()
{
	Close();
	m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (-1 != m_Socket)
	{
		return true;
	}
	return false;
}

void Tcp::Close()
{
	if (-1 != m_Socket)
	{
#ifdef WIN32
		closesocket(m_Socket);
#else
		close(m_Socket);
#endif
		m_Socket = -1;
	}
}

bool Tcp::SetBlocking()
{
#ifdef WIN32
	unsigned long ul = 0;
	return (ioctlsocket(m_Socket, FIONBIO, (unsigned long*)&ul) != SOCKET_ERROR);
#else
	int lOptions;
	lOptions = fcntl(m_Socket, F_GETFL);
	if (lOptions >= 0 && (lOptions & O_NOINHERIT))
	{
		lOptions ~= O_NOINHERIT;
		if (fcntl(m_Socket, F_SETFL, lOptions) >= 0)
		{
			return 1;
		}
	}
	return 0;
#endif
}

bool Tcp::SetNonblocking()
{
#ifdef WIN32
	unsigned long ul = 1;
	return (ioctlsocket(m_Socket, FIONBIO, (unsigned long*)&ul) != SOCKET_ERROR);
#else
	int lOptions;
	lOptions = fcntl(m_Socket, F_GETFL);
	if (lOptions >= 0)
	{
		lOptions |= O_NOINHERIT;
		if (fcntl(m_Socket, F_SETFL, lOptions) >= 0)
		{
			return 1;
		}
		return 0;
	}
#endif
}

int Tcp::Connect(char* apAddr, int aPort)
{
	struct  sockaddr_in lAddr;
	lAddr.sin_family = AF_INET;
	lAddr.sin_addr.s_addr = inet_addr(apAddr);
	lAddr.sin_port = htons(aPort);
	return connect(m_Socket, (sockaddr*)&lAddr, sizeof(lAddr));
}

int Tcp::Send(char* apBuffer, int aLength)
{
	return send(m_Socket, apBuffer, aLength, 0);
}

int Tcp::Recv(char* apBuffer, int aLength)
{
	return recv(m_Socket, apBuffer, aLength, 0);
}

int Tcp::SendFull(char *apBuffer, int aLength)
{
	int lToLength = 0;
	int lLength = 0;
	while (true)
	{
		lLength = Send(apBuffer + lToLength, aLength - lToLength);
		if (lLength > 0)
		{
			lToLength += lLength;
			if (lToLength == aLength)
			{
				break;
			}
		}
		else
		{
			if (errno == EINTR)
			{
				continue;
			}
			else if (errno == EAGAIN)
			{
#ifdef WIN32
				Sleep(1);
#else
				usleep(1);
#endif
				continue;
			}
			else
			{
				break;
			}
		}
	}
	return lToLength;
}
int Tcp::RecvFull(char *apbuffer, int aLength)
{
	int lToLength = 0;
	int lLength = 0;
	while (true)
	{
		lLength = Recv(apbuffer + lToLength, aLength - lToLength);
		if (lLength > 0)
		{
			lToLength += lLength;
			if (lToLength == aLength)
			{
				break;
			}
		}
		else if (lLength < 0)
		{
			if (errno == EINTR || errno == EAGAIN || errno == EWOULDBLOCK)
			{
				continue;
			}
			else
			{
				int i = errno;
				break;
			}
		}
		else
		{
			break;
		}
	}
	return lToLength;
}
