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
#include<vector>
using namespace std;
class Context
{
private:
	string str;//字符串信息，用于文本文件
	long size;//占用大小
public:
	Context();
	void setStr(string tmp);
	string* getStr();
	long getSize();
};
