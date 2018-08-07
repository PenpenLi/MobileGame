#include "MyClass.h"


MyClass::MyClass()
:num(5)
{
}


MyClass::~MyClass()
{
}

void MyClass::SetFoo(int i)
{
	num = i;
}