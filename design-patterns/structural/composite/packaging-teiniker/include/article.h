#ifndef _ARTICLE_H_
#define _ARTICLE_H_

#include <node.h>

class Article : public Node
{
	private:
		std::string _name;
		int _quantity;
		
	public:                
		Article(const std::string& name, const int quantity, const int weight); 
		virtual ~Article(void) {}
		
		std::string name(void);
		
		virtual int totalWeight();
};

#endif /*ARTICLE_H*/
