#include <line.h>

using namespace std;

OrderLine::OrderLine(int id, int quantity, Product* product)
	: id_{id}, quantity_{quantity}, product_{product}
{
}

// Copy Constructor
OrderLine::OrderLine(const OrderLine& old)
{
	id_ = old.id_;
	quantity_ = old.quantity_;
	product_ = new Product(*old.product_);	
}


int OrderLine::id(void)
{
	return id_;
}

int OrderLine::quantity(void)
{
	return quantity_;
}

Product* OrderLine::product(void)
{
	return product_;
}
void OrderLine::product(Product* product)
{
	product_ = product;
}
