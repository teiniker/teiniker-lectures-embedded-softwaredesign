#include <iostream>
#include <string>
#include <algorithm>
#include <list_to_upper.h>

using namespace std;

// Primitive Operation (required override)
string ListToUpper::modifyElement(const string& element) 
{
    string lower = element;
    transform(lower.begin(), lower.end(), lower.begin(), ::toupper);
    return lower;
}

