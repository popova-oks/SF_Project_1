#include "Messages.h"

void Messages::set_message(IObserver* sender, std::string message)
{
	msg_.insert({ sender, message });
}
