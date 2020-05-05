#include <FileService.h>

#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>

using namespace std;

FileService::FileService(const string& filename)
{
	if(filename.length() == 0)
		throw invalid_argument("Invalid filename!");
	
	filename_ = filename;	
}


string FileService::readFile()
{
	ifstream file(filename_.c_str());	
	if(!file)
		throw FileNotFound("File " + filename_ + " not found!"); 
	
	string content;
	while(file) 
	{ 
		string line;
		getline(file, line); 
		content.append(line);
    }     
    return content;
}


void FileService::writeFile(const string& content)
{
	// TODO	
	
}
