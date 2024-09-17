#ifndef _ORDER_H_
#define _ORDER_H_

#include <string>
#include <vector>

#include <OrderLine.h>

class Order 
{
	private:
		int id_; 
		std::string name_;
		std::vector<OrderLine*> lines_;  // ---[*]-> OrderLine
 
	public:
		Order(int id, const std::string& name);	
		Order(const Order& old);	// Copy Constructor   
		   
		int id(void);		
		std::string name(void);
		
		void addLine(OrderLine* line);
		OrderLine* line(int index);
		int numberOfLines(void);
 };

#endif /*_MAIL_H_ */
