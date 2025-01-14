#ifndef _NODE_H_
#define _NODE_H_

#include <memory>
#include <string>

class Node
{
	private:
		int _weight;
		
	public:                
		Node(const int weight) : _weight{weight} {}
		virtual ~Node(void) {}
		
		int weight(void)
		{
			return _weight;
		}

		// Navigation
		virtual void addNode(std::shared_ptr<Node> node) 
		{
			// Default implementation
			(void)node; // Suppress unused parameter warning
		};	
		
		// Abstract Operations
		virtual int totalWeight() = 0;
 };

#endif /*_NODE_H_ */
