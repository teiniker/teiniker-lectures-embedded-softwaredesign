#ifndef _ORDER_H_
#define _ORDER_H_

#include <string>
#include <vector>

#include <OrderLine.h>

//using namespace std;

class Order 
{
	private:
		int id_; 
		string name_;
		std::vector<OrderLine*> lines_;  // ---[*]-> OrderLine
 
	public:
		Order(int id, const string& name);	
		   
		int id(void);		
		string name(void);
		
		void addLine(OrderLine* line);
		OrderLine* line(int index);
		int numberOfLines(void);
 };

#endif /*_MAIL_H_ */
