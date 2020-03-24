#ifndef _FILE_H_
#define _FILE_H_

#include <string>

#include <Directory.h>

using namespace std;

class File 
{
	private:
		string name_; 
		size_t size_;
		Directory* directory_;
 
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
