#ifndef _INTEGER_SEQUENCE_H_
#define _INTEGER_SEQUENCE_H_

class IntegerSequence 
{
	public:
		IntegerSequence(void); 

		// Static class methods
		static void init(int value);
		static int next(void); 
		
		int id(void);

	private:
		static int _value;	// Static class variable
		int _id;
 };

#endif /*_INTEGER_SEQUENCE_H_ */
