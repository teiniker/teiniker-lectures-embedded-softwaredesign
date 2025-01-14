#include <article.h>

using namespace std;

Article::Article(const string& name, const int quantity, const int weight)
	: Node(weight), _name{name}, _quantity{quantity} 
{}
	
	
string Article::name(void)
{
	return _name;
}
	
int Article::totalWeight()
{
	return _quantity * weight();
}
