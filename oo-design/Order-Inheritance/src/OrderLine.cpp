#include <OrderLine.h>

OrderLine::OrderLine(int id, int quantity, Product* product)
	: Entity(id), quantity_{quantity}, product_{product}
{
}

int OrderLine::quantity(void)
{
	return quantity_;
}

Product* OrderLine::product(void)
{
	return product_;
}
