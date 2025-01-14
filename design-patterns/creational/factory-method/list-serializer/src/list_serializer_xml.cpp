
#include <list_serializer_xml.h>

using namespace std;

#include <sstream>

std::string ListSerializerXml::serialize(const vector<int>& list) 
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
