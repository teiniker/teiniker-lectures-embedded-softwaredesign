#ifndef _FILE_H_
#define _FILE_H_

#include <string>
#include "directory.h"

class File 
{
	private:
		std::string _name; 
		size_t _size;
		Directory* _directory = NULL;	// ---[0..1]-> Directory
 
	public:
		File(const std::string& name, size_t size);
    
		std::string name(void);
		void name(const std::string& name);
		
		size_t size(void);
		void size(size_t size);
		
		// Association: File ---[1]-> Directory
		Directory* directory(void);
		void directory(Directory* directory);
 };

#endif /*_FILE_H_ */
