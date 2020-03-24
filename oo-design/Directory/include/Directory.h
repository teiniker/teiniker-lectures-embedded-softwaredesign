#ifndef _DIRECTORY_H_
#define _DIRECTORY_H_

#include <string>
#include <vector>

using namespace std;

class File; // forward declaration

class Directory 
{
	private:
		string name_;
		vector<File*> files_;
 
	public:
		Directory(const string& name);
		
		string name(void);
		void name(const string& name);
		
		void addFile(File* file);
		File* file(int index);
		int numberOfFiles(void);
 };

#endif /*_DIRECTORY_H_ */
