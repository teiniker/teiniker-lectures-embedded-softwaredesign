#include <Controller.h>

#include <iostream>

using namespace std;

Controller::Controller()
{
	try
	{
		io_ = new GPIO();
		
	}
	catch(std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
		throw ControllerException("Can't access GPIO!");
	}
}

Controller::~Controller()
{
	if(io_ != NULL)
		delete io_; 
}
