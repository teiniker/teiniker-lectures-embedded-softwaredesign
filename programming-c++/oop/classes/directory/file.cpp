#include <string>
#include "file.h"

File::File(const string& name, size_t size)
    : _name{name}, _size{size}
{
    _directory = NULL;
}

string File::name(void)
{
    return _name;
}
void File::name(const string& name)
{
    _name = name;
}

size_t File::size(void)
{
    return _size;
}
void File::size(size_t size)
{
    _size = size;
}

// Association: File ---[1]-> Directory
Directory* File::directory(void)
{
    return _directory;
}
void File::directory(Directory* directory)
{
    _directory = directory;
}