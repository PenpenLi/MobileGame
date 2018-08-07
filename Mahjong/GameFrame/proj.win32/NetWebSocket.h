#pragma once
#include "cocos2d.h"
#include "stdio.h"
#include "network/WebSocket.h"
USING_NS_CC;
using namespace cocos2d::network;
using namespace std;
class NetWebSocket
	:public WebSocket::Delegate
{
public:
	NetWebSocket();
	~NetWebSocket();

public:
	void create(const string sendMsg);

	//��ʱ��
	void sendMsg(const string &msg);
	void sendMsg(const int &msgType, const int &protocol);
	void sendMsg(const int &msgType, const int &protocol, const string &msg);

	virtual void onOpen(WebSocket* ws);
	//virtual void onMessage(WebSocket*ws, WebSocket::Data& data);
	virtual void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data);
	virtual void onClose(WebSocket* ws);
	virtual void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error);

	//�ַ���Ϣ
	//string DispatchMsg(string &msgbuf);
private:
	WebSocket *_websocket;
	string strIP;
	
	//�ַ���Ϣ
	CC_SYNTHESIZE(string, msgbuf, DispatchMsg);
};

