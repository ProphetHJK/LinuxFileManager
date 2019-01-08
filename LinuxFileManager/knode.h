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

//inode�ļ�,�����ļ��Ļ�����Ϣ
class knode
{
private:
	string filename;//�ļ���
	string pathname;//����·��
	int nodeid;//node��ţ����մ���˳��ָ��
	long ctime;//����޸�ʱ��,Ҳ�ܱ�ʾ����ʱ��
	long vtime;//������ʱ��
	unsigned long bytesize;//�ļ���С���ֽڣ����4GB
	
	knode* parent;//���ڵ��ָ��
	vector<knode*> child_list;//�ӽڵ������ָ��

public:
	
	//���캯��
	knode(string name, bool dir, knode *parentnode);
	~knode();
	//���븸�ڵ㣬ÿ��һ��
	void addChildnode(knode *childnode);
	//�����ӽڵ㣬ÿ��һ��
	void setParent(knode *parentnode);
	//�Ƴ��ӽڵ㣬ÿ��һ��
	void removeChild(knode *childnode);
	bool isdir;//�Ƿ�ΪĿ¼
	//��ʾĿ¼���ļ�
	void showChild();
	//����·��,����·��string
	string getPath();
	//��ȡUnixʱ���
	long getTime();
	//Ŀ¼���ļ����Ƿ��ظ�
	bool isDuplicate(string filename, bool isdir);
	//�����ӽڵ�
	knode* findKnode(string name,bool dir);
	//��ȫ������Ϣ
	knode* copyKnode();
	string getfilename();
	long getvtime();
	long getctime();
	long getbytesize();
	void setfilename(string name);
	void setctime();
	void setvtime();
	void setbytesize(long size);
	knode* getParent();
	int getNodeid();
	vector<knode*> &getchildlist();
};