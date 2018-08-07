#include "UpdateService.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
//#include "CFileUtil.h"
//#include "UpdateHelper.h"
//#include "Utility.h"
//#include "sha1.h"
#include <iostream>
//json
#include "json/rapidjson.h"
#include "json/document.h"

UpdateService::UpdateService()
:tickets(100)
, m_Stop(true)
, m_Version(-1)
, m_BigVersion(-1)
, m_VersionSize(-1)
, m_Handler(0)
{
}

UpdateService::~UpdateService()
{
	//Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
}



void UpdateService::initInfo(string versionUrl, string UpdateUrl, int DefaultSize)
{
	//m_UpdateInfo.VersionUrl = versionUrl;
	//m_UpdateInfo.UpdateUrl = UpdateUrl;
	//m_UpdateInfo.DefaultSize = DefaultSize;
}
		

void UpdateService::Start(string info, long aPartner, long aGameID, long aCurrentVersion, long aTimeOut, long aPlatForm, int aHandler)
{
	////info = {\"VersionUrl\":\"wdk\"}
	CCLOG("UpdateService::Start......1");
	rapidjson::Document dj;
	dj.Parse<0>(info.c_str());

	m_UpdateInfo.VersionUrl = dj["Version"].GetString();
	//m_CurrentVersion = aCurrentVersion;
	//m_CurrentPartner = aPartner;
	//m_GameID = aGameID;
	//m_platform = aPartner;
	//SetScriptHandler(aHandler);

	//m_Path = CCFileUtils::sharedFileUtils()->getWritablePath();
	//CFileUtil::MakeDir(m_Path.c_str());
	Director::getInstance()->getScheduler()->scheduleUpdateForTarget(this, 0, false);
	tickets = 100;
	Run();
}

void UpdateService::update(float dt)
{
	/*CCLOG("..................update");
	LuaStack* lpStack = LuaEngine::getInstance()->getLuaStack();
	lpStack->pushString("StartGame");
	lpStack->pushInt(1);
	lpStack->pushBoolean(false);
	lpStack->clean();*/
	SendMsg();

}
/**********************DownloadVersion***end*********************/
/***************************thread_begin************************************/
void UpdateService::Run()
{
	
	/*std::thread tA(&UpdateService::myThreadA, this);
	std::thread tB(&UpdateService::myThreadB, this);
	tA.join();
	tB.join();*/

	m_Stop = false;
	std::thread RT(&UpdateService::RunTask, this);
	RT.detach();
}

void UpdateService::myThreadA()
{
	while (true)
	{
		mutex.lock();
		if (tickets > 0)
		{
#if WIN32
			Sleep(1);
#else
			unsleep(1);
#endif
			//CCLOG("A sell %d", tickets--);
			std::cout<<"A sell "<<tickets--<<endl;
			mutex.unlock();
		}
		else
		{
			std::cout<<"A sell break"<<endl;
			mutex.unlock();
			break;
		}

	}
}

void UpdateService::myThreadB()
{
	while (true)
	{
		mutex.lock();
		if (tickets>0)
		{
#if WIN32
			Sleep(1);
#else
			unsleep(1);
#endif
			//CCLOG("B sell %d", tickets--);
			std::cout << "B sell " << tickets-- << endl;
			mutex.unlock();
		} 
		else
		{
			cout<<"B sell break"<<endl;
			mutex.unlock();
			break;
		}
	}
}

/***************************thread_end************************************/

void UpdateService::SendCommand(UpdateCommand aCommand, void* apData)
{
	m_Operation.Command = aCommand;
	m_Operation.pData = apData;
}
void UpdateService::SendCommand(UpdateCommand aCommand, string &aAddress, string &aSavePath)
{
	m_Operation.Command = aCommand;
	m_Operation.m_Address = aAddress;
	m_Operation.m_SavePath = aSavePath;
}

void UpdateService::SendData(void* apData)
{
	m_Operation.pData = apData;
}


void UpdateService::PushMsg(UpdateMsg& aMsg)
{
	m_MessagesList.push_back(aMsg);
	Director::getInstance()->getScheduler()->resumeTarget(this);
}

void UpdateService::SendMsg()
{
	std::list<UpdateMsg>::iterator lItor;
	for (lItor = m_MessagesList.begin(); lItor != m_MessagesList.end(); ++lItor)
	{
		UpdateMsg const& lMsg = *lItor;
		switch (lMsg.command)
		{
		case CheckVersion:
			CCLOG("............SendMsg:CheckVersion");
			SendCheckVersion(lMsg);
			break;
		case DownloadCheckList:
			break;
		case DownloadFile:
			break;
		case DownloadFullVersion:
			break;
		case Exit:
			break;
		case Downloading:
			break;
		case CanStartGame:
			break;
		case DownloadDone:
			break;
		case DownloadingFull:
			break;
		default:
			break;
		}
	}
	m_MessagesList.clear();
	Director::getInstance()->getScheduler()->pauseTarget(this);
}

void UpdateService::RunTask()
{
	while (!m_Stop)
	{
		//sem_wait(m_pMain);
		switch (m_Operation.Command)
		{
		case CheckVersion:
			CheckUpdateVersion();
			CCLOG("............RunTask:CheckVersion");
			break;
		case DownloadCheckList:
			//DownLoadCheckList(m_Version);
			break;
		case DownloadFile:
			//DownloadFiles((long)m_Operation.pData);
			break;
		case DownloadFullVersion:
			//DownloadVersion(m_Operation.m_Address, m_Operation.m_SavePath);
			break;
		case Exit:
			break;
		}
	}
	Director::getInstance()->getScheduler()->unscheduleUpdateForTarget(this);
}


void UpdateService::checkVersion()
{
	SendCommand(CheckVersion, 0);
}

void UpdateService::OnCheckVersion(bool aResult, int aVersion, int aBigVersion, int aFlag, int aVersionSize)
{
	UpdateMsg lMsg;
	lMsg.command = CheckVersion;
	lMsg.result = aResult;
	lMsg.vaule = aVersion;
	lMsg.bigver = aBigVersion;
	lMsg.versize = aVersionSize;
	lMsg.flag = aFlag;
	PushMsg(lMsg);
}

void UpdateService::SendCheckVersion(UpdateMsg const & aMsg)
{
	LuaStack* lpStack = LuaEngine::getInstance()->getLuaStack();
	lpStack->pushString("CheckVersion");
	lpStack->pushBoolean(aMsg.result);
	lpStack->pushInt(aMsg.vaule);
	lpStack->pushInt(aMsg.flag);
	lpStack->pushInt(aMsg.bigver);
	lpStack->pushInt(aMsg.versize);
	lpStack->executeFunctionByHandler(m_Handler, 6);
	lpStack->clean();
}

bool UpdateService::CheckUpdateVersion()
{
	size_t lPos = m_UpdateInfo.VersionUrl.find_last_of(":");
	string lAddress = m_UpdateInfo.VersionUrl.substr(0, lPos);
	string lPort = m_UpdateInfo.VersionUrl.substr(lPos + 1);
	
	bool lConnect = false;
	/*if ()
	{
	}*/
	lConnect = (bool)m_Operation.pData;

	int lFlag = 0;
	if (lConnect && GetVerionFormServer(m_Version, m_BigVersion, lFlag, m_VersionSize))
	{
		OnCheckVersion(true, m_Version, m_BigVersion, lFlag, m_VersionSize);
	}
	else
	{
		OnCheckVersion(false, m_Version, m_BigVersion, lFlag, m_VersionSize);
	}

	return true;
}

bool UpdateService::GetVerionFormServer(int& aVersion, int& aBigVersion, int& aFlag, int& aVersionSize)
{
	return true;
}

