#include <list_processor.h>

using namespace std;

void ListProcessor::process(vector<std::string>& list)
{
	for (size_t i = 0; i < list.size(); ++i)
	{
		string element = modifyElement(list[i]);  // call abstract primitive method
		printElement(element);                         // call hook method
		list[i] = element;
	}
}

void ListProcessor::printElement(const std::string& element)
{
	// default behavior - do nothing
	(void)element;
}