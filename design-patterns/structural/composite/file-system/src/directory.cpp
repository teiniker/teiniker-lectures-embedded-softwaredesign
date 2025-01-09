#include <vector>
#include <directory.h>

using namespace std;

Directory::Directory(const string& name) : Node(name) 
{
}

void Directory::addNode(shared_ptr<Node> node)
{
	_nodes.push_back(node);
}

int Directory::numberOfFiles(void)
{
	int number = 0;
	
	for(shared_ptr<Node> node : _nodes)
		number += node->numberOfFiles();	

	return number;
}

size_t Directory::numberOfBytes(void)
{
	size_t size = 0;
	for(shared_ptr<Node> node : _nodes)
		size += node->numberOfBytes();	

	return size;
}
