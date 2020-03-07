#include <ComplexNumber.h>
#include <iostream>

using namespace std;

int main(void)
{
	ComplexNumber c = ComplexNumber(1.0, 1.0);
	
	cout << '('
		 << c.re()
		 << ','
		 << c.im()
		 << ")\n";  
}
 
