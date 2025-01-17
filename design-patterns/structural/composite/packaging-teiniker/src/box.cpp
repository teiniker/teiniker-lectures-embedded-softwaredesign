#include <vector>
#include <box.h>

using namespace std;

Box::Box(const int weight) : Node(weight) 
{
}

void Box::addNode(shared_ptr<Node> node)
{
	_nodes.push_back(node);
}

int Box::totalWeight(void)
{
	int total = weight();
	
	for(shared_ptr<Node> node : _nodes)
		total += node->totalWeight();	

	return total;
}
