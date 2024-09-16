#ifndef _DIRECTORY_H_
#define _DIRECTORY_H_

#include <Node.h>
#include <string>
#include <vector>
#include <memory>

class Box : public Node
{	
	private:
		std::vector<std::shared_ptr<Node>> nodes_;
	
	public:                
		Box(const int weight);
		virtual ~Box(void) {}
		
		virtual void addNode(std::shared_ptr<Node> node);	
		virtual int totalWeight();
};

#endif /*DIRECTORY_H*/
