#include "order.h"

using namespace std;

Order::Order(int id, const string& name)
	: _id{id}, _name{name}
{
}

// Copy Constrcutor
Order::Order(const Order& old)
{
	_id = old._id;
	_name = old._name;
	for(OrderLine* line : old._lines)
	{
		_lines.push_back(new OrderLine(*line));
	}
}

int Order::id(void) const
{
	return _id;	
}

string Order::name(void) const
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
