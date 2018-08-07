#pragma once
#include "cocos2d.h"
#include <vector>
#include <string>
USING_NS_CC;
using namespace cocos2d;
using namespace std;
class ImageLoader
{
public:
	ImageLoader();
	~ImageLoader();
	void AddImageAsync(vector<string>& sFiles);

	void Load();
	void LoadOneDone(Texture2D* texture);
private:
	int m_index;
	vector<string> m_FileList;
};

