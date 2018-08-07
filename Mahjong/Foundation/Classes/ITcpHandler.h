#pragma once
struct ITcpHandler
{
	virtual void HandleConnect(bool aConnected) = 0;
	virtual void HandleRecv(const char* apBuffer, int aSize) = 0;
	virtual void HandleSend(const char* apBuffer, int aSize) = 0;
	virtual void HandleError() = 0;
};

//typedef class UpdateInfo
//{
//	char* VersionUrl;
//	//string UpdateUrl;
//	//int DefaultSize;
//};