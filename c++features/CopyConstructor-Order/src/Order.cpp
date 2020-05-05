#include <Order.h>

using namespace std;

Order::Order(int id, const string& name)
	: id_{id}, name_{name}
{
}

// Copy Constrcutor
Order::Order(const Order& old)
{
	id_ = old.id_;
	name_ = old.name_;
	for(OrderLine* line : old.lines_)
	{
		lines_.push_back(new OrderLine(*line));
	}
}

int Order::id(void)
{
	return id_;	
}

string Order::name(void)
{
	return name_;
}

void Order::addLine(OrderLine* line)
{
	lines_.push_back(line);
}

OrderLine* Order::line(int index)
{
	return lines_[index];
}

int Order::numberOfLines(void)
{
	return lines_.size();
}	
