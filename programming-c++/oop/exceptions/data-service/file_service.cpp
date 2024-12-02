#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>

#include "file_service.h"

using namespace std;

FileService::FileService(const string& filename)
{
	if(filename.length() == 0)
		throw invalid_argument("Invalid filename!");
	
	_filename = filename;	
}

string FileService::readFile()
{
	ifstream file(_filename.c_str());	
	if(!file)
		throw FileNotFound("File " + _filename + " not found!"); 
	
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
