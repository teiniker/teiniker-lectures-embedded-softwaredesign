#include "resistor.h"

using namespace std;

string Resistor::to_csv(void) const
{
	char buffer[100];
    snprintf(buffer, sizeof(buffer), "Resistor,%d,%.3E,%s", id(), value(), unit().c_str());
    return string(buffer);

}
