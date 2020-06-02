#include <File.h>

using namespace std;

File::File(const std::string& name, const size_t size)
	: Node(name), size_{size}
{}
	
int File::numberOfFiles()
{
	return 1;
}

size_t File::numberOfBytes()
{
	return size_;
}
