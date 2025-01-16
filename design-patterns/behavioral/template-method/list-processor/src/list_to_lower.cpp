#include <iostream>
#include <string>
#include <algorithm>
#include <list_to_lower.h>

using namespace std;

// Primitive Operation (required override)
string ListToLower::modifyElement(const string& element) 
{
    string lower = element;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

// Hook Operation (optional override)
void ListToLower::printElement(const string& element)
{
    cout << "> " << element << endl;
}
