
#include <list_serializer_json.h>

using namespace std;

#include <sstream>

std::string ListSerializerJson::serialize(const vector<int>& list) 
{
    std::ostringstream out; 
    out << "{\"list\":[";
    for (size_t i=0; i<list.size(); i++)
    {
        out << list[i];
        if (i != list.size() - 1) 
        { 
            out << ",";
        }
    }
    out << "]}";
    return out.str(); 
}
