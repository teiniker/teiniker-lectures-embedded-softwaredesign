#ifndef _FILE_H_
#define _FILE_H_

#include <string>
#include "directory.h"

using namespace std;

class File 
{
	private:
		string _name; 
		size_t _size;
		Directory* _directory = NULL;	// ---[0..1]-> Directory
 
	public:
		File(const string& name, size_t size);
    
		string name(void);
		void name(const string& name);
		
		size_t size(void);
		void size(size_t size);
		
		// Association: File ---[1]-> Directory
		Directory* directory(void);
		void directory(Directory* directory);
 };

#endif /*_FILE_H_ */
