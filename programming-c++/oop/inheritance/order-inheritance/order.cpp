#include "order.h"

using namespace std;

Order::Order(int id, const string& name)
	: Entity(id), _name{name}
{	
}

string Order::name(void)
{
	return _name;
}

void Order::addLine(OrderLine* line)
{
	_lines.push_back(line);
}

OrderLine* Order::line(int index)
{
	return _lines[index];
}

int Order::numberOfLines(void)
{
	return _lines.size();
}	
