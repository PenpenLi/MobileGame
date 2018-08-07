#include "NetSession.h"

NetSession* NetSession::s_pInst = NULL;
NetSession::NetSession()
{
	nts = new NetWebSocket();
}


NetSession::~NetSession()
{
}

NetSession* NetSession::Inst()
{
	if (!s_pInst)
	{
		s_pInst = new NetSession();
	}
	return s_pInst;
}

void NetSession::Destory()
{

}

void NetSession::create()
{

}

void NetSession::post(const int &serverType, const int &protocol)
{
	nts->sendMsg(serverType, protocol);
}

void NetSession::post(const string &msg)
{
	CCLOG("post");
	nts->sendMsg(msg);
}

void NetSession::post(const int &serverType, const int &protocol, const string &msg)
{
	nts->sendMsg(serverType, protocol, msg);
}

string NetSession::GetDispatchMessage()
{
	return nts->getDispatchMsg();
}