#include <Order.h>

Order::Order(int id, const string& name)
	: Entity(id), name_{name}
{
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
