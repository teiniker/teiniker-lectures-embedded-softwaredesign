#include <Directory.h>
#include <vector>

using namespace std;

Directory::Directory(const string& name) : Node(name) 
{
}

void Directory::addNode(shared_ptr<Node> node)
{
	nodes_.push_back(node);
}

int Directory::numberOfFiles(void)
{
	int number = 0;
	
	for(shared_ptr<Node> node : nodes_)
		number += node->numberOfFiles();	

	return number;
}

size_t Directory::numberOfBytes(void)
{
	size_t size = 0;
	for(shared_ptr<Node> node : nodes_)
		size += node->numberOfBytes();	

	return size;
}
