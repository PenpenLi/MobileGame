#pragma once
#include "cocos2d.h"
#include "NetWebSocket.h"
using namespace std;
using namespace cocos2d;

class NetSession
{
public:
	NetSession();
	~NetSession();

	static NetSession* Inst();
	void Destory();
	void create();
	void post(const string &msg);
	void post(const int &serverType, const int &protocol);
	void post(const int &serverType, const int &protocol, const string &msg);
	string GetDispatchMessage();//分发消息
private:
	static NetSession *s_pInst;
	
	NetWebSocket *nts;
};

