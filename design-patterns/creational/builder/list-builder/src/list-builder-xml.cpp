
#include <list-builder-xml.h>

using namespace std;

#include <sstream>

ListBuilder& ListBuilderXml::item(const std::string& s)
{
    list.push_back(s); 
    return *this; 
}

std::string ListBuilderXml::toXml() const 
{
    std::ostringstream out; 
    out << "<list>";
    for (size_t i=0; i<list.size(); i++)
    {
        out << "<item>" << list[i] << "</item>";
    }
    out << "</list>";
    return out.str(); 
}
