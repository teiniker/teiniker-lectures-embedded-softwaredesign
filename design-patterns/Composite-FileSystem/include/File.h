#ifndef _FILE_H_
#define _FILE_H_

#include <Node.h>

class File : public Node
{
	private:
		size_t size_;
		
	public:                
		File(const std::string& name, const size_t size); 
		virtual int numberOfFiles();
		virtual size_t numberOfBytes();
};

#endif /*FILE_H*/
