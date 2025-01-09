#include <file.h>

using namespace std;

File::File(const string& name, const size_t size)
	: Node(name), _size{size}
{}
	
int File::numberOfFiles()
{
	return 1;
}

size_t File::numberOfBytes()
{
	return _size;
}
