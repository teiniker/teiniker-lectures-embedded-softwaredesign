#include <product.h>

using namespace std;

Product::Product(int id, const string& description, long price) 
	: id_{id}, description_{description}, price_{price}
{
}

// Copy Constructor
Product::Product(const Product& old)
{
	id_ = old.id_;
	description_ = old.description_;
	price_ = old.price_;
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
