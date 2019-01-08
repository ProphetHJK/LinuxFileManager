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

//inode的简化,单个文件的基本信息
class knode
{
private:
	string filename;//文件名
	string pathname;//绝对路径
	int nodeid;//node编号，按照创建顺序指定
	long ctime;//最后修改时间,也能表示创建时间
	long vtime;//最后访问时间
	unsigned long bytesize;//文件大小（字节）最大4GB
	
	knode* parent;//父节点的指针
	vector<knode*> child_list;//子节点的向量指针

public:
	
	//构造函数
	knode(string name, bool dir, knode *parentnode);
	~knode();
	//加入父节点，每次一个
	void addChildnode(knode *childnode);
	//加入子节点，每次一个
	void setParent(knode *parentnode);
	//移除子节点，每次一个
	void removeChild(knode *childnode);
	bool isdir;//是否为目录
	//显示目录下文件
	void showChild();
	//计算路径,返回路径string
	string getPath();
	//获取Unix时间戳
	long getTime();
	//目录下文件名是否重复
	bool isDuplicate(string filename, bool isdir);
	//检索子节点
	knode* findKnode(string name,bool dir);
	//完全复制信息
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