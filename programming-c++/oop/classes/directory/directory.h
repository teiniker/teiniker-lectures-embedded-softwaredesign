#ifndef _DIRECTORY_H_
#define _DIRECTORY_H_

#include <string>
#include <vector>

class File; // forward declaration

// Directory  ----[*]->  File
// Directory  <-[1]----  File

// Directory -[1]---[*]- File (bidirectional)
class Directory 
{
	private:
		std::string _name;
		std::vector<File*> _files;  // ---[*]-> File
 
	public:
		Directory(const std::string& name);
		
		std::string name(void) const;
		void name(const std::string& name);
		
		// ---[*]-> File
		void addFile(File* file);
		File* file(int index);
		int numberOfFiles(void);
 };

#endif /*_DIRECTORY_H_ */
