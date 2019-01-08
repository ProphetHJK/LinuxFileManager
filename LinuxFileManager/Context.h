#pragma once
#include<cstdlib>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/time.h>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
class Context
{
private:
	string str;
	long size;
public:
	Context();
	void setStr(string tmp);
	string* getStr();
	long getSize();
};