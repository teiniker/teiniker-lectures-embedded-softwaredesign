#ifndef _NODE_H_
#define _NODE_H_

#include <memory>
#include <string>

class Node
{
	private:
		std::string name_;
		
	public:                
		virtual ~Node(void) {}
		
		Node(const std::string& name) : name_{name} {}
	
		std::string name(void)
		{
			return name_;
		}

		// Navigation
		virtual void addNode(std::shared_ptr<Node> node) 
		{
			// Default implementation
		};	
		
		// Abstract Operations
		virtual int numberOfFiles() = 0;
		virtual size_t numberOfBytes() = 0;
 };

#endif /*_NODE_H_ */
