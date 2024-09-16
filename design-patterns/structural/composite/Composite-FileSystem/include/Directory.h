#ifndef _DIRECTORY_H_
#define _DIRECTORY_H_

#include <Node.h>
#include <string>
#include <vector>

class Directory : public Node
{
	private:
		std::vector<std::shared_ptr<Node>> nodes_; 
		
	public:                
		Directory(const std::string& name);
		virtual ~Directory(void) {}
		
		virtual void addNode(std::shared_ptr<Node> node);	
		virtual int numberOfFiles();
		virtual size_t numberOfBytes();
};

#endif /*DIRECTORY_H*/
