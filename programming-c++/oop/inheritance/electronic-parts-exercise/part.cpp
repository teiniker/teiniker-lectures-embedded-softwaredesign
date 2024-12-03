#include "part.h"

using namespace std;

Part::Part(const int id, const double value, const string& unit)
	: _id(id), _value(value), _unit(unit)
{
}

int Part::id() const
{
	return _id;
}

double Part::value() const
{
	return _value;
}

string Part::unit() const
{
	return _unit;
}