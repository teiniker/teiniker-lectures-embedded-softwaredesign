#include <DataService.h>

#include <string>
#include <sstream>

using namespace std;

DataService::DataService(FileService* fservice) : fservice_{fservice} {}

vector<int> DataService::readData()
{
	try
	{
		string content = fservice_->readFile();
		vector<string> string_values = split(content,',');
		vector<int> data;
		for(string value : string_values)
		{
			data.push_back(stoi(value));
		}
		return data;
	}
	catch(const FileNotFound& e)
	{
		throw DataProcessingException(e.what());
	} 
}

void DataService::writeData(const vector<int>& data)
{
	// TODO
}


vector<string> DataService::split (const string &s, char delim) 
{
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

