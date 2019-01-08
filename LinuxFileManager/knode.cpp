#include "knode.h"
#include "main.h"
knode::knode(string name, bool dir, knode *parentnode)
{
	setfilename(name);
	isdir = dir;
	setParent(parentnode);
	setvtime();
	setctime();
	nodeid = knodeid;
	knodeid++;
	setbytesize(0);
	cout << "File has been created.The knodeid is " << nodeid << endl;
}
knode::~knode()
{}
int knode::getNodeid()
{
	return nodeid;
}
knode* knode::getParent() {
	return parent;
}
long knode::getTime()
{
	return time(nullptr);
}
void knode::setfilename(string name)
{
	filename = name;
}
void knode::setctime()
{
	ctime = getTime();
}
void knode::setvtime()
{
	vtime = getTime();
}
void knode::setbytesize(long size)
{
	bytesize = size;
}
void knode::addChildnode(knode *childnode)
{
	child_list.push_back(childnode);
}
void knode::setParent(knode *parentnode)
{
	parent = parentnode;
}
void knode::removeChild(knode *childnode)
{
	for (vector<knode*>::iterator it = child_list.begin(); it != child_list.end();)
	{
		if (*it == childnode)
		{
			it = child_list.erase(it);
			break;
		}
		else
		{
			++it;
		}
	}
}
string knode::getfilename()
{
	return filename;
}
long knode::getvtime()
{
	return vtime;
}
long knode::getctime()
{
	return ctime;
}
long knode::getbytesize()
{
	return bytesize;
}
string knode::getPath()
{

}
void knode::showChild()
{
	cout << "knodeid\tfilename\tcreatetime\tvisittime\tisdir\tsize" << endl;
	for (vector<knode*>::iterator it = child_list.begin(); it != child_list.end();++it)
	{
		
		cout << (*it)->getNodeid() <<"\t"<< (*it)->getfilename() << "\t" << (*it)->getctime() << "\t" << (*it)->getvtime() << "\t" << (*it)->isdir << "\t" << (*it)->getbytesize() << endl;
	}
}
bool knode::isDuplicate(string filename,bool isdir)
{
	for (vector<knode*>::iterator it = child_list.begin(); it != child_list.end();)
	{
		//类型相同且名字相同曾不能创建
		if ((*it)->isdir == isdir && (*it)->filename == filename)
		{
			return true;
		}
		else
		{
			++it;
		}
	}
	return false;
}
knode* knode::findKnode(string name,bool dir)
{
	for (vector<knode*>::iterator it = child_list.begin(); it != child_list.end();)
	{
		if ((*it)->isdir == dir && (*it)->filename == name)
		{
			return (*it);
		}
		else
		{
			++it;
		}
	}
}
vector<knode*> &knode::getchildlist()
{
	return child_list;
}
//复制信息
knode* knode::copyKnode()
{
	knode *tmp = new knode(getfilename(), isdir, NULL);
	tmp->setbytesize(getbytesize());
	return tmp;
}