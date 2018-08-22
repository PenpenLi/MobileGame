#include "cocos2d.h"
#include "GameFramePlatform.h"
USING_NS_CC;
using namespace std;

enum iPlatForm
{
	p_UNKNOWN = 0,
	p_IOS = 1,
	p_ANDROID =2,
	p_WIN32 = 3,
};

GameFramePlatform::GameFramePlatform()
{
}


GameFramePlatform::~GameFramePlatform()
{
}

int GameFramePlatform::getExternStorePath()
{
	int m_platForm = p_UNKNOWN;
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	{
		m_platForm = p_ANDROID;
	}
	else if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	{
		m_platForm = p_IOS;
	}
	else if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	{
		m_platForm = p_WIN32;
	}
	else
	{
		m_platForm = p_UNKNOWN;
	}
	return m_platForm;
}

int GameFramePlatform::getPlatform()
{
	int m_PlatForm = CC_PLATFORM_UNKNOWN;
	switch (CC_TARGET_PLATFORM)
	{
	case CC_PLATFORM_IOS:
		m_PlatForm = CC_PLATFORM_IOS;
		break;
	case CC_PLATFORM_ANDROID:
		m_PlatForm = CC_PLATFORM_ANDROID;
		break;
	case CC_PLATFORM_WIN32:
		m_PlatForm = CC_PLATFORM_WIN32;
		break;
	case CC_PLATFORM_MAC:
		m_PlatForm = CC_PLATFORM_MAC;
		break;
	default:
		break;
	}
	return m_PlatForm;
}