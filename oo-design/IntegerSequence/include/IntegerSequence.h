#ifndef _INTEGERSEQUENCE_H_
#define _INTEGERSEQUENCE_H_

class IntegerSequence 
{
	private:
		static int value_;
		int id_;
				
	public:
		IntegerSequence(void);

		static void init(int value);
		static int next(void); 
		
		int id(void);
 };

#endif /*_INTEGERSEQUENCE_H_ */
