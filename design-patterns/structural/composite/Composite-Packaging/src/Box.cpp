#include <Box.h>
#include <vector>

using namespace std;

Box::Box(const int weight) : Node(weight) 
{
}

void Box::addNode(shared_ptr<Node> node)
{
	nodes_.push_back(node);
}

int Box::totalWeight(void)
{
	int total = weight();
	
	for(shared_ptr<Node> node : nodes_)
		total += node->totalWeight();	

	return total;
}
