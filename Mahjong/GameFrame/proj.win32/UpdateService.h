#pragma once
//#include "../../Foundation/Classes/Thread.h"
#include "cocos2d.h"
#include <string.h>
//#include "../../Foundation/Classes/ITcpHandler.h"
//#include <semaphore.h>
//#include "../../Foundation/Classes/TcpService.h"
//#include "HttpDownloader.h"

using namespace cocos2d;
using namespace std;
USING_NS_CC;

//#define SHA1_SIZE	20
//#define ZIP_UPDATELIST_NAME_FORMAT "CheckList_Star.ini_%d00.zip"
//#define UNZIP_UPDATELIST_NAME "CheckList_Star.ini"
//#define UPDATEEFILE_NAME_FORMAT(name) name + "_%d00.zip"
//#define UPDATE_CHECKLIST_HEAD "[masters]\r\n"
//#define UPDATE_CHECKLIST_TAIL "[version]\r\n"
//#define OPERATION_NOTIFICATION "Agen Operation Notification"

//
//struct CheckItem
//{
//	char filename[512];
//	unsigned long zipsize;
//	unsigned long unzipsize;
//	unsigned long version;
//	bool bUpdata;
//	char sha1[SHA1_SIZE * 2 + 1];
//};
//
enum UpdateCommand
{
	CheckVersion,
	DownloadCheckList,
	DownloadFile,
	DownloadFullVersion,
	Exit,

	Downloading,
	CanStartGame,
	DownloadDone,

	DownloadingFull,

	CommandMax
};
//
//
//struct Progress
//{
//	Progress() :total(1), addUp(0), delta(0), flag(0){}
//	long total;
//	long addUp;
//	long delta;
//	int flag;
//};
//
struct UpdateOperation
{
	UpdateOperation()
	{
		Command = CommandMax;
		pData = 0;
	}
	UpdateCommand Command;
	void* pData;
	std::string m_Address;
	std::string m_SavePath;
};
//
struct UpdateInfo
{
	string VersionUrl;
	string UpdateUrl;
	int DefaultSize;
};
//
//
struct UpdateMsg
{
	UpdateCommand command;
	bool result;
	int vaule;
	int bigver;
	int versize;
	int writeSize;
	int dFileSize;
	int dNow;
	int dTotal;
	int flag;
};

class UpdateService
	:public Ref
{
public:
	
	UpdateService(void);
	~UpdateService(void);
	bool init() { return true; };
	CREATE_FUNC(UpdateService);
	void initInfo(string versionUrl, string UpdateUrl, int DefaultSize );
	void Start(string info, long aPartner, long aGameID, long aCurrentVersion, long aTimeOut, long aPlatForm, int aHandler);

	
//	virtual void Stop();
	void RunTask();
//
	void update(float dt);
//	void PushMsg(UpdateMsg &aMsg);
//	void SendMsg();
//	
//
//	virtual void HandleConnect(bool aConnected);
//	virtual void HandleRecv(const char* apBuffer, int aSize);
//	virtual void HandleSend(const char* apBuffer, int aSize);
//	virtual void HandleError();
//	
//	void StartGame();
//	void SendStartGame(UpdateMsg const& aMsg);
//	void SendCheckVersion(UpdateMsg const& aMsg);
//
//	void SetScriptHandler(int aHandler){ m_Handler = aHandler; }
//

//
//
//private:
//	bool CheckUpdateVersion();
//	bool DownLoadCheckList(int aVersion);
//	bool DownloadFiles(int aIndex);
//	void DownloadVersion(std::string& aAddress, std::string& aPath);
//
//
//	int TimedWaitSub(int aSec);
//	bool GetVersionFormServer(int& aVersion, int& aBigVersion, int& aFlag, int& aVersionSize);
//	void OnCheckVersion(bool aResult, int aVersion, int aBigVersion, int aFlag, int aVersionSize);
//
//
//	void WriteFile(HttpClient *sender, HttpResponse *response);
//	void HandleCheckList(HttpClient *sender, HttpResponse *response);
//
//	void SendData(void* apData);
//	void WaitSub();
//	bool GetUpdateFiles(HttpResponse *lpResponse);
//
//	//解析提取的文件
//	bool ParseUpdateDataInCheckList(char const* apFile);
//	bool checkLocalFileWithCheckItem(CheckItem *pItem);
//
//
//	void HandleDownLoadFile(HttpClient *sender, HttpResponse *response);
//	void HanldeDownloadSize(HttpClient *sender, HttpResponse *response);
//	void OnDownloadProgress(int aSize, int aFileSize, int aTotalSize);
//	bool SaveFile(HttpData const& aData, HttpResponse *apResponse);
//	void OnDownload(bool aResult, int aIndex);
//	void OnDownloadDone(bool aResult, int aCount);
//
//
//	string GetAppFileName(std::string& AppDownloadAddress);
//	void HanldeDownloadFullSize(HttpClient *sender, HttpResponse *response);
//	void OnDownloadFullProgress(int aSize, int aFileSize, int aTotalSize);
//	bool SaveFullFile(HttpData const& aData, HttpResponse *apResponse);
//	void OnDownloadFullVersion(bool aRet);
//private:
//	long m_Handler;
//
//
//private:
//	//热更
//	string m_HotFixVersion;
//	string m_HotFixPath;
//	//整包
//	
//	string m_BigPath;
//
//	//客户端
//	string m_ApkVersion;
//	string m_ApkBigVerion;
//
//	string m_ApkPath;
//	string m_ApkSavePath;
//	
//	
//	std::string m_Path;	
//	int m_CurrentVersion;
//	int m_CurrentPartner;	//合作伙伴ID
//	int m_GameID;	//
//	int m_platform;	//平台
//	
//
//	TcpService m_TcpService;
//
//	UpdateInfo m_UpdateInfo;
//	UpdateOperation m_Operation;
//
//	std::list<UpdateMsg> m_MessagesList;
//
//	sem_t * m_pMain;
//	sem_t* m_pSub;
//	MutexLock m_Lock;
//	HttpDownloader m_DownLoader;
//private:
//	char m_Buf[1024];
//	int m_RecvSize;

//	long m_TotalUpdateSize;
//	long m_DownloadSize;
//	long m_DownloadFileIndex;
//	long m_TimeOut;
//	
//
//
//	std::vector<CheckItem> m_vUpdateItem;
public:
	void SendMsg();

	
private:
	bool m_Stop;
	std::list<UpdateMsg> m_MessagesList;

public:
	void SendCommand(UpdateCommand aCommand, void* apData);
	void SendCommand(UpdateCommand aCommand, string &aAddress, string &aSavePath);
	void SendData(void* apData);
	void PushMsg(UpdateMsg& aMsg);
private:
	UpdateOperation m_Operation;

public:
	void checkVersion();
	void OnCheckVersion(bool aResult, int aVersion, int aBigVersion, int aFlag, int aVersionSize);

public:
	bool CheckUpdateVersion();
	bool GetVerionFormServer(int& aVersion, int& aBigVersion, int& aFlag, int& aVersionSize);
	void SendCheckVersion(UpdateMsg const& aMsg);
private:
	UpdateInfo m_UpdateInfo;
	
	int m_Version;
	int m_BigVersion;
	int m_VersionSize;


	long m_Handler;
	
public:
	void myThreadA();
	void myThreadB();
	void Run();
private:
	int tickets;
	std::mutex mutex;
};

