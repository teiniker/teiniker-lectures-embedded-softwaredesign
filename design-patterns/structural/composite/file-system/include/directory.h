#ifndef _DIRECTORY_H_
#define _DIRECTORY_H_

#include <node.h>
#include <string>
#include <vector>

class Directory : public Node
{
	private:
		std::vector<std::shared_ptr<Node>> _nodes; 
		
	public:                
		Directory(const std::string& name);
		virtual ~Directory(void) {}
		
		virtual void addNode(std::shared_ptr<Node> node) override;	
		virtual int numberOfFiles() override;
		virtual size_t numberOfBytes() override;
};

#endif /*DIRECTORY_H*/
