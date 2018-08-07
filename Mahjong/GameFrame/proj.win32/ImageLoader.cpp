#include "ImageLoader.h"


ImageLoader::ImageLoader()
{
}


ImageLoader::~ImageLoader()
{
}

void ImageLoader::AddImageAsync(vector<string>& sFiles)
{
	if (sFiles.size()>0)
	{
		m_index = 0;
		m_FileList = sFiles;
		Load();
	}
}

void ImageLoader::Load()
{
	Director::getInstance()->getTextureCache()->addImageAsync(m_FileList[m_index].c_str(), CC_CALLBACK_1(ImageLoader::LoadOneDone, this));
}

void ImageLoader::LoadOneDone(Texture2D* texture)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("OneImageLoaded");
	if (!m_FileList.empty())
	{
		/*string str = "res/";
		str += m_FileList[m_index];
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(m_FileList[m_index].c_str(), texture);*/
	}
	if (++m_index<m_FileList.size())
	{
		CCLOG("m_index.........%d", m_index);
		Load();
	}
	else
	{
		EventCustom lEvent("ImageLoadDone");
		Director::getInstance()->getEventDispatcher()->dispatchEvent(&lEvent);
	}
	CCLOG("loading resource is sucess!", m_index);
}