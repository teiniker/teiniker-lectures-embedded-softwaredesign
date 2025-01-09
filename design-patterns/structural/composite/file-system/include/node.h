#ifndef _NODE_H_
#define _NODE_H_

#include <memory>
#include <string>

class Node
{
	private:
		std::string _name;
		
	public:                
		virtual ~Node(void) {}
		
		Node(const std::string& name) : _name{name} {}
	
		std::string name(void)
		{
			return _name;
		}

		// Navigation
		virtual void addNode(std::shared_ptr<Node> node) 
		{
			// Default implementation
			(void)node; // Suppress unused parameter warning
		};	
		
		// Abstract Operations
		virtual int numberOfFiles() = 0;
		virtual size_t numberOfBytes() = 0;
 };

#endif /*_NODE_H_ */
