#ifndef _ARTICLE_H_
#define _ARTICLE_H_

#include <Node.h>

class Article : public Node
{
	private:
		std::string name_;
		int quantity_;
		
	public:                
		Article(const std::string& name, const int quantity, const int weight); 
		virtual ~Article(void) {}
		
		std::string name(void);
		
		virtual int totalWeight();
};

#endif /*ARTICLE_H*/
