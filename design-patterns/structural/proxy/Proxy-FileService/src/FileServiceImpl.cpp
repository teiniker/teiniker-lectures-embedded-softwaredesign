#include <FileServiceImpl.h>

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

string FileServiceImpl::readFile(const string& filename)
{
	ifstream file(filename.c_str());	
	if(!file)
		throw FileNotFound("File " + filename + " not found!"); 
	
	string content;
	while(file) 
	{ 
		string line;
		getline(file, line); 
		content.append(line);
    }     
    return content;
}
