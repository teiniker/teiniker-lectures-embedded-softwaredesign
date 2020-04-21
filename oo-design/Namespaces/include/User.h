#ifndef _USER_H_
#define _USER_H_

#include <string>

namespace org	// org
{
	namespace se	// org::se
	{
		namespace lab	// org::se::lab
		{	
			// using namespace std;		// namespace of the standard library code

			class User 
			{
				private:
					int id_; 
					std::string username_;
					std::string password_;
			 
				public:                
					User(const int id, const std::string& username, const std::string& password);

					int id();
					std::string username(void);		
					std::string password();
			 };
		} // end of lab
	} // end of se
} // end of org

#endif /*_USER_H_ */
