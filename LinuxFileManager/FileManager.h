#pragma once
#include "knode.h"

class FileManager
{
private:
	long long maxspace;//最大空间
	vector<knode*> fileblocks;//记录文件信息
	long long freespace;//剩余空间
	long long usedspace;//已使用空间
	knode *nowdir;//当前目录
	knode *rootdir;
public:
	
	//初始化
	FileManager();
	//删除文件
	void deleteFile(knode *node);
	//删除文件
	void deleteDir(knode *node);
	//创建文件
	knode* createFile(string name, knode *parent);
	//创建目录
	knode* createDir(string name,  knode *parent);
	//创建文件在当前目录
	knode* createFile(string name);
	//创建目录在当前目录
	knode* createDir(string name);
	//重命名文件
	void renameFile(string newname, knode *node);
	//重命名目录
	void renameDir(string newname, knode *node);
	//移动文件
	void moveFile(knode *node,knode *newdir);
	//移动目录
	void moveDir(knode *node,knode *newdir);
	//复制文件
	void copyFile(knode *node, knode *newdir);
	//复制目录
	void copyDir(knode *node, knode *newdir);
	//显示当前目录下所有文件及目录
	void showFile();
	//进入目录
	void enterDir(string dir);
	//根据string解析knode
	knode *findFile(string filename,bool isdir);
	//显示绝对路径
	void showPWD(knode *node);
	//获取当前目录
	knode* getNowdir();
	//文本内容修改
	void editText(knode *node,string str);
	//文本内容获取
	string *catText(knode *node);
	//获取文件系统信息
	void showDf();
	void test();
};