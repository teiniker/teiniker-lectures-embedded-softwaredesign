#ifndef _RANGE_H_
#define _RANGE_H_

#include <cstdint>

class Range 
{
	private:
		int32_t value_;
		int32_t min_;
		int32_t max_;
 
	public:
		// Constructor
		Range(const int32_t min, const int32_t max);

		// Accessor methods
		int32_t value(void) const;
		void value(const int32_t value);

		// Operator overloading
		bool operator==(const Range& other) const;
		bool operator!=(const Range& other) const;
		bool operator<(const Range& other) const;
		bool operator>(const Range& other) const;
		bool operator<=(const Range& other) const;
		bool operator>=(const Range& other) const;
};

#endif /*_RANGE_H_ */
