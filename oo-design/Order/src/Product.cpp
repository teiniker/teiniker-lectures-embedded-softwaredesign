#include <Product.h>

Product::Product(int id, const string& description, long price) 
	: id_{id}, description_{description}, price_{price}
{
}

int Product::id(void)
{
	return id_;
}

string Product::description(void)
{
	return description_;
}

long Product::price(void)
{
	return price_;
} 
