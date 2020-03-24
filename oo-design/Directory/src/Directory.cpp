#include <Directory.h>
#include <File.h>

using namespace std;

Directory::Directory(const string& name)
	: name_{name}
{
}

string Directory::name(void)
{
	return name_;
}
void Directory::name(const string& name)
{
	name_ = name;
}

void Directory::addFile(File* file)
{
	files_.push_back(file);
}
File* Directory::file(int index)
{
	return files_[index];
}
int Directory::numberOfFiles(void)
{
	return files_.size();
}
