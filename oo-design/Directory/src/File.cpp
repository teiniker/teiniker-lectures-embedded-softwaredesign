#include <File.h>

File::File(const string& name, size_t size)
    : name_{name}, size_{size}
{
    directory_ = NULL;
}

string File::name(void)
{
    return name_;
}
void File::name(const string& name)
{
    name_ = name;
}

size_t File::size(void)
{
    return size_;
}
void File::size(size_t size)
{
    size_ = size;
}

// Association: File ---[1]-> Directory
Directory* File::directory(void)
{
    return directory_;
}
void File::directory(Directory* directory)
{
    directory_ = directory;
}
