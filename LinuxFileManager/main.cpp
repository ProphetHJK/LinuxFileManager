#include"FileManager.h"
using namespace std;

void StartMenu(FileManager *filemanager)
{
	string command;
	string command1;
	cout << "Welcome to LinuxFileManager!" << endl;
	cout << "Use \"help\" to see what you can do." << endl;
	while (1) 
	{
		cout << "ubuntu@ubuntu:";
		filemanager->showPWD(filemanager->getNowdir());
		cout<<"~$ ";
		cin >> command;
		if (command == "help")
		{
			cout << "ls\t\t\t\tList information about the FILEs (the current directory by default)" << endl;
			cout << "pwd\t\t\t\tShow absolute path" << endl;
			cout << "cd DIRECTORY\t\t\tEnter CHILD-DIRECTORY(use ./ enter Parent DIRECTORY)" << endl;
			cout << "mkdir DIRECTORY\t\tCreate the DIRECTORY(ies), if they do not already exist." << endl;
			cout << "touch FILE\t\t\tUpdate the access and modification times of each FILE to the current time." << endl;
			cout << "rm FILE\t\t\t\tRemove (unlink) the FILE(s)" << endl;
			cout << "rmd DIRECTORY\t\t\tRemove directories and their contents recursively" << endl;
			cout << "mv SOURCE TARGET\t\tMove SOURCE(s) to DIRECTORY" << endl;
			cout << "mvd SOURCEDIRECTORY TARGET\tMove SOURCEDIRECTORY to DIRECTORY" << endl;
			cout << "cp SOURCE TARGET\t\tCopy SOURCE to DIRECTORY" << endl;
			cout << "cpd SOURCEDIRECTORY TARGET\tCopy SOURCEDIRECTORY to DIRECTORY" << endl;
			cout << "vi FILE\t\t\t\tEDIT FILE" << endl;
			cout << "cat FILE\t\t\tConcatenate FILE to standard output" << endl;
			cout << "rename FILE TARGETNAME\t\tRename file" << endl;
			cout << "renamed DIRECTORY TARGETNAME\tRename dictionary" << endl;
			cout << "df\t\t\t\tShow information about the file system" << endl;
		}
		else if (command == "ls")
		{
			filemanager->showFile();
		}
		else if (command == "cd")
		{
			cin >> command;
			filemanager->enterDir(command);		
		}
		else if (command == "pwd")
		{
			filemanager->showPWD(filemanager->getNowdir());
			cout << endl;
		}
		else if (command == "mkdir")
		{
			cin >> command;
			filemanager->createDir(command);
		}
		else if (command == "touch")
		{
			cin >> command;
			filemanager->createFile(command);
		}
		else if (command == "rm")
		{
			cin >> command;
			filemanager->deleteFile(filemanager->findFile(command,false));
		}
		else if (command == "rmd")
		{
			cin >> command;
			filemanager->deleteDir(filemanager->findFile(command, true));
		}
		else if (command == "mv")
		{
			cin >> command;
			cin >> command1;
			filemanager->moveFile(filemanager->findFile(command,false), filemanager->findFile(command1,true));
		}
		else if (command == "mvd")
		{
			cin >> command;
			cin >> command1;
			filemanager->moveDir(filemanager->findFile(command, true), filemanager->findFile(command1, true));
		}
		else if (command == "cp")
		{
			cin >> command;
			cin >> command1;
			filemanager->copyFile(filemanager->findFile(command, false), filemanager->findFile(command1, true));
		}
		else if (command == "cpd")
		{
			cin >> command;
			cin >> command1;
			filemanager->copyDir(filemanager->findFile(command, true), filemanager->findFile(command1, true));
		}
		else if (command == "vi")
		{
			cin >> command;
			if (filemanager->findFile(command, false)!= NULL)
			{
				cout << "Enter your string here:";
				cin >> command1;
				filemanager->editText(filemanager->findFile(command, false), command1);
			}
			else
			{
				cout << "Can't find this file!";
			}
		}
		else if (command == "cat")
		{
			cin >> command;
			if (filemanager->findFile(command, false) != NULL)
			{
				cout << *filemanager->catText(filemanager->findFile(command, false)) << endl;
			}
			else
			{
				cout << "Can't find this file!";
			}

		}
		else if (command == "rename")
		{
			cin >> command;
			cin >> command1;
			filemanager->renameFile(command1, filemanager->findFile(command, false));
		}
		else if (command == "renamed")
		{
			cin >> command;
			cin >> command1;
			filemanager->renameFile(command1, filemanager->findFile(command,true));
		}
		else if (command == "df")
		{
			filemanager->showDf();
		}
		else if (command == "exit")
		{
			break;
		}
		else
		{
			cout << "Wrong command!Please try again.Use \"help\" to see all commands."<<endl;
		}
	}
	
}


int main() {
	FileManager *filemanager = new FileManager();
	StartMenu(filemanager);
	return 0;
}