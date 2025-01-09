#ifndef _FILE_H_
#define _FILE_H_

#include <node.h>

class File : public Node
{
	private:
		size_t _size;
		
	public:                
		File(const std::string& name, const size_t size); 
		virtual ~File(void) {}
		
		virtual int numberOfFiles() override;
		virtual size_t numberOfBytes() override;
};

#endif /*FILE_H*/
