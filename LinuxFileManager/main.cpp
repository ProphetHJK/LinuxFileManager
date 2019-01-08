#include<cstdlib>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/time.h>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include"FileManager.h"
using namespace std;

//´´½¨Ä¿Â¼
void createDir(char *pathname,__mode_t tmode=0775)
{


	int isRight=mkdir(pathname, tmode);
	if (isRight == -1)
		cout << "error" << endl;
	else
		cout << "success" << endl;
}

	


int main() {
	FileManager *filemanager = new FileManager();
	filemanager->test();
	return 0;
}