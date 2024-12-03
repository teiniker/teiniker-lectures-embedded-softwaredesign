#include "resistor.h"

using namespace std;

string Resistor::to_csv(void) const
{
    return "Resistor," + Part::to_csv();
}
