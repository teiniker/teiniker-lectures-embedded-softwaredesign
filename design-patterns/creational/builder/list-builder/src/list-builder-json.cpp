
#include <list-builder-json.h>

using namespace std;

#include <sstream>

ListBuilder& ListBuilderJson::item(const std::string& s)
{
    list.push_back(s); 
    return *this; 
}

std::string ListBuilderJson::toJson() const 
{
    std::ostringstream out; 
    out << "{\"list\":[";
    for (size_t i=0; i<list.size(); i++)
    {
        out << "\"" << list[i] << "\"";
        if (i != list.size() - 1) 
        { 
            out << ",";
        }
    }
    out << "]}";
    return out.str(); 
}
