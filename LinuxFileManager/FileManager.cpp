#include"FileManager.h"
FileManager::FileManager()
{
	maxspace = 4294967295;
	freespace = maxspace;
	usedspace = 0;
	knode *rootdir = new knode("/", true, NULL);
	nowdir = rootdir;
	fileblocks.push_back(rootdir);
}
void  FileManager::deleteDir(knode *node)
{
	if (node->getNodeid() == 0)
	{
		cout << "Can't delete root dictionary!" << endl;
		return;
	}
	//当子目录不为空时递归删除所有子目录
	for (vector<knode*>::iterator it = node->getchildlist().begin(); it != node->getchildlist().end()&& !node->getchildlist().empty();++it)
	{
		if ((*it)->isdir == true)
		{
			deleteDir(*it);
		}
		else
		{
			deleteFile(*it);
		}
	}
	node->getParent()->removeChild(node);
	for (vector<knode*>::iterator fbit = fileblocks.begin(); fbit != fileblocks.end();)
	{
		if (*fbit == node)
		{
			fileblocks.erase(fbit);
			
			cout << "Delete " << node->getfilename() << " completed" << endl;
			break;
		}
		else
		{
			++fbit;
		}
	}
	delete node;
	return;
}
void FileManager::deleteFile(knode *node)
{
	if (node->getNodeid() == 0)
	{
		cout << "Can't delete root dictionary!" << endl;
		return;
	}
	node->getParent()->removeChild(node);
	for (vector<knode*>::iterator it = fileblocks.begin(); it != fileblocks.end();)
	{
		if (*it==node)
		{
			fileblocks.erase(it);	
			usedspace -= (*it)->getbytesize();
			freespace = maxspace - usedspace;
			cout << "Delete " << node->getfilename() << " completed" << endl;
			break;
		}
		else
		{
			++it;
		}
	}
	delete node;
	return;
}
knode* FileManager::createFile(string name, knode *parent)
{
	if (parent->isDuplicate(name, false))
	{
		cout << "There is already a \"" << name << "\" in parent dictionary!" << endl;
	}
	else
	{
		
		knode *tmp = new knode(name, false, parent);
		parent->addChildnode(tmp);
		fileblocks.push_back(tmp);
		cout << "Create " << tmp->getfilename() << " completed" << endl;
		return tmp;
	}
	return NULL;
}
knode* FileManager::createFile(string name)
{
	if (nowdir->isDuplicate(name, false))
	{
		cout << "There is already a \"" << name << "\" in parent dictionary!" << endl;
	}
	else
	{
		knode *tmp = new knode(name, false, nowdir);
		nowdir->addChildnode(tmp);
		fileblocks.push_back(tmp);
		cout << "Create " << tmp->getfilename() << " completed" << endl;
		return tmp;
	}
	return NULL;
}
knode* FileManager::createDir(string name, knode *parent)
{
	if (parent->isDuplicate(name, true))
	{
		cout << "There is already a \"" << name << "\" in parent dictionary!" << endl;
	}
	else
	{

		knode *tmp = new knode(name, true, parent);
		parent->addChildnode(tmp);
		fileblocks.push_back(tmp);
		cout << "Create " << tmp->getfilename() << " completed" << endl;
		return tmp;
	}
	return NULL;
}
knode* FileManager::createDir(string name)
{
	if (nowdir->isDuplicate(name, true))
	{
		cout << "There is already a \"" << name << "\" in parent dictionary!" << endl;
	}
	else
	{
		knode *tmp = new knode(name, true, nowdir);
		nowdir->addChildnode(tmp);
		fileblocks.push_back(tmp);
		cout << "Create " << tmp->getfilename() << " completed" << endl;
		return tmp;
	}
	return NULL;
}
//重命名文件
void FileManager::renameFile(string oldname, string newname, knode *node)
{
	node->setfilename(newname);
}
//重命名目录
void FileManager::renameDir(string oldname, string newname, knode *node)
{
	node->setfilename(newname);
}
void FileManager::moveFile(knode *node, knode *newdir)
{
	node->getParent()->removeChild(node);
	newdir->addChildnode(node);
}
//移动目录
void FileManager::moveDir(knode *node, knode *newdir)
{
	node->getParent()->removeChild(node);
	newdir->addChildnode(node);
}
//复制文件
void FileManager::copyFile(knode *node, knode *newdir)
{
	knode *tmp = node->copyKnode();
	tmp->setParent(newdir);
	newdir->addChildnode(tmp);
	fileblocks.push_back(tmp);
	usedspace += tmp->getbytesize();
	freespace = maxspace - usedspace;
	cout << "Copy " << tmp->getfilename() << " to "<<newdir->getfilename()<<" completed" << endl;
}
//复制目录,bug无法复制本目录到子目录
void FileManager::copyDir(knode *node, knode *newdir)
{
	knode *tmp = node->copyKnode();
	tmp->setParent(newdir);
	newdir->addChildnode(tmp);
	fileblocks.push_back(tmp);
	//当子目录不为空时递归复制所有子目录,
	for (vector<knode*>::iterator it = node->getchildlist().begin(); it != node->getchildlist().end() && !node->getchildlist().empty(); ++it)
	{
		if ((*it)->isdir == true)
		{
			copyDir(*it,tmp);
		}
		else
		{
			copyFile(*it,tmp);
		}
	}
	cout << "Copy " << tmp->getfilename() << " to " << newdir->getfilename() << " completed" << endl;
}
void FileManager::test()
{
	knode* tmp = createDir("test");
	
	createFile("test3", createDir("test2", createDir("test1", tmp)));
	tmp->showChild();
	//deleteDir(tmp->findKnode("test1",true));
	knode* tmp2 = createDir("copy");
	copyDir(tmp, tmp->getchildlist()[0]);
	tmp->getchildlist()[0]->showChild();
}
