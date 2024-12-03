#include <string>
#include "capacitor.h"

using namespace std;

string Capacitor::to_csv(void) const
{
	char buffer[100];
    snprintf(buffer, sizeof(buffer), "Capacitor,%d,%.3E,%s", id(), value(), unit().c_str());
    return string(buffer);
}
