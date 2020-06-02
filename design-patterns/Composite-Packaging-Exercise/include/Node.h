#ifndef _NODE_H_
#define _NODE_H_

#include <memory>
#include <string>

class Node
{
	private:
		int weight_;
		
	public:                
		virtual ~Node(void) {}
		
		Node(const int weight) : weight_{weight} {}
	
		int weight(void)
		{
			return weight_;
		}

		// Navigation
		virtual void addNode(std::shared_ptr<Node> node) 
		{
			// Default implementation
		};	
		
		// Abstract Operations
		virtual int totalWeight(void) = 0;
 };

#endif /*_NODE_H_ */
