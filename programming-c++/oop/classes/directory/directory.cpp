#include "directory.h"
#include "file.h"

using namespace std;

Directory::Directory(const string& name)
	: _name{name}
{
}

string Directory::name(void)
{
	return _name;
}
void Directory::name(const string& name)
{
	_name = name;
}

void Directory::addFile(File* file)
{
	_files.push_back(file);
}
File* Directory::file(int index)
{
	return _files[index];
}
int Directory::numberOfFiles(void)
{
	return _files.size();
}
