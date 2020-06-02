#include <Article.h>

using namespace std;

Article::Article(const std::string& name, const int quantity, const int weight)
	: Node(weight), name_{name}, quantity_{quantity} 
{}
	
	
string Article::name(void)
{
	return name_;
}
	
int Article::totalWeight()
{
	return quantity_ * weight();
}
