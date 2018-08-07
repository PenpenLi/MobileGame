#pragma once
#include "cocos2d.h"
using namespace cocos2d;
class MyClass:public Ref
{
public:
	MyClass();
	~MyClass();
	bool init(){ return true; }
	CREATE_FUNC(MyClass);

	void SetFoo(int i);
	int GetFoo(){ return num; }
private:
	int num;
};

