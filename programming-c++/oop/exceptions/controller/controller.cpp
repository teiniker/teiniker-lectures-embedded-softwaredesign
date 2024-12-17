#include "controller.h"

#include <iostream>

using namespace std;

Controller::Controller()
{
	try
	{
		_io = new GPIO();	
	}
	catch(std::runtime_error& e)
	{
		string msg;
		msg.append("Can't access GPIO! (because: ");
		msg.append(e.what());
		msg.append(")"); 
		throw ControllerException(msg);
	}
}

Controller::~Controller()
{
	if(_io != NULL)
		delete _io; 
}
