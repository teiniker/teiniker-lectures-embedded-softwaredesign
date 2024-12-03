#include <string>
#include "capacitor.h"

using namespace std;

string Capacitor::to_csv(void) const
{
    return "Capacitor," + Part::to_csv();
}
