#include "knode.h"
class FileManager
{
private:
	long long maxspace;//���ռ�
	vector<knode*> fileblocks;//��¼�ļ���Ϣ
	long long freespace;//ʣ��ռ�
	long long usedspace;//��ʹ�ÿռ�
	knode *nowdir;//��ǰĿ¼

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
	void renameFile(string oldname, string newname, knode *node);
	//������Ŀ¼
	void renameDir(string oldname, string newname, knode *node);
	//�ƶ��ļ�
	void moveFile(knode *node,knode *newdir);
	//�ƶ�Ŀ¼
	void moveDir(knode *node,knode *newdir);
	//�����ļ�
	void copyFile(knode *node, knode *newdir);
	//����Ŀ¼
	void copyDir(knode *node, knode *newdir);
	void test();
};