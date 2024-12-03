#ifndef _PART_H_
#define _PART_H_

#include <string>
#include "part.h"

class Part // abstract class
{
	private:
		int _id;
		double _value; 
		std::string _unit;
 
	public:                
		Part(const int id, const double value, const std::string& unit);
		virtual ~Part(void) {}
		
		// Accessor methods
		int id() const;
		double value() const;
		std::string unit() const;	

		// Operations
		virtual std::string to_csv(void) const;
 };

#endif /*_PART_H_ */
