#include "NetWebSocket.h"
#include "NetWebSocket.h"


NetWebSocket::NetWebSocket()
:_websocket(nullptr)
, strIP("ws://mj.5xx.club:8001/ChatServer?data={'Protocol':3,'Protocol2':1}")	//120.24.228.114，120.24.219.60
{
	_websocket = new WebSocket();
	if (!_websocket->init(*this,strIP))
	{
		CC_SAFE_DELETE(_websocket);
	}
}


NetWebSocket::~NetWebSocket()
{
	if (_websocket)
	{
		_websocket->close();
	}
}

//void NetWebSocket::create(const string sendMsg)
//{
//	if (_websocket->getReadyState() ==WebSocket::State::OPEN)
//	{
//		string reult = "{\'Protocol\':3, \'Protocol2\':1}";
//		//string msg = jsonEncode(3, 1);
//		_websocket->send(sendMsg);
//	}
//}

void NetWebSocket::sendMsg(const string &msg)
{
	if (_websocket->getReadyState() == WebSocket::State::OPEN)
	{
		CCLOG("sendMsg:%s", msg.c_str());
		_websocket->send(msg);
	}
}
void NetWebSocket::sendMsg(const int &msgType, const int &protocol)
{
	if (_websocket->getReadyState() == WebSocket::State::OPEN)
	{
		//string  msg = jsonEncode(msgType, protocol);
		//_websocket->send(msg);
	}
}

void NetWebSocket::sendMsg(const int &msgType, const int &protocol, const string &msg)
{
	if (_websocket->getReadyState() == WebSocket::State::OPEN)
	{
		//string msg = jsonEncode(msgType, protocol, msg);
		//_websocket->send(msg);
	}
}


void NetWebSocket::onOpen(WebSocket* ws)
{
	if (ws == _websocket)
	{
		CCLOG("websocket is open!");
	}
}
void NetWebSocket::onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data)
{
	if (!data.isBinary)
	{
		//string textStr = string("reponse text msg:") + data.bytes;
		unsigned char *decodeData = NULL;
		int len = base64Decode((unsigned char*)data.bytes, (unsigned int)data.len, &decodeData);
		CCLOG((char*)decodeData);
		string data = string((const char*)decodeData, len);
		CCLOG(data.c_str());
		setDispatchMsg(data);
		EventCustom lEvent("DispatchMsg");
 		Director::getInstance()->getEventDispatcher()->dispatchEvent(&lEvent);
	}
	else
	{
		CCLOG("没收到当前协议正确的返回信息");
	}
}
void NetWebSocket::onClose(WebSocket* ws)
{
	if (ws ==_websocket)
	{
		_websocket = nullptr;
	}
	CC_SAFE_DELETE(ws);
}
void NetWebSocket::onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error)
{
	CCLOG("websock is error");
}

//string NetWebSocket::DispatchMsg(string &msgbuf)
//{
//	return msgbuf;
//}