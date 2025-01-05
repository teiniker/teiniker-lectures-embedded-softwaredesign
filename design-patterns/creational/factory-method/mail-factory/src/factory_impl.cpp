
#include <memory>
#include <factory_impl.h>

using namespace std;

shared_ptr<Mail> FactoryImpl::createMail(const string& address)
{
	shared_ptr<Mail> mail(new Mail(address));
	return mail;
}
