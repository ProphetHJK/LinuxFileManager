#pragma once
#include "knode.h"

class FileManager
{
private:
	long long maxspace;//���ռ�
	vector<knode*> fileblocks;//��¼�ļ���Ϣ
	long long freespace;//ʣ��ռ�
	long long usedspace;//��ʹ�ÿռ�
	knode *nowdir;//��ǰĿ¼
	knode *rootdir;
public:
	
	//��ʼ��
	FileManager();
	//ɾ���ļ�
	void deleteFile(knode *node);
	//ɾ���ļ�
	void deleteDir(knode *node);
	//�����ļ�
	knode* createFile(string name, knode *parent);
	//����Ŀ¼
	knode* createDir(string name,  knode *parent);
	//�����ļ��ڵ�ǰĿ¼
	knode* createFile(string name);
	//����Ŀ¼�ڵ�ǰĿ¼
	knode* createDir(string name);
	//�������ļ�
	void renameFile(string newname, knode *node);
	//������Ŀ¼
	void renameDir(string newname, knode *node);
	//�ƶ��ļ�
	void moveFile(knode *node,knode *newdir);
	//�ƶ�Ŀ¼
	void moveDir(knode *node,knode *newdir);
	//�����ļ�
	void copyFile(knode *node, knode *newdir);
	//����Ŀ¼
	void copyDir(knode *node, knode *newdir);
	//��ʾ��ǰĿ¼�������ļ���Ŀ¼
	void showFile();
	//����Ŀ¼
	void enterDir(string dir);
	//����string����knode
	knode *findFile(string filename,bool isdir);
	//��ʾ����·��
	void showPWD(knode *node);
	//��ȡ��ǰĿ¼
	knode* getNowdir();
	//�ı������޸�
	void editText(knode *node,string str);
	//�ı����ݻ�ȡ
	string *catText(knode *node);
	//��ȡ�ļ�ϵͳ��Ϣ
	void showDf();
	void test();
};