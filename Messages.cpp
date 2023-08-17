#include "Messages.h"

IObserver* Messages::get_Sender(std::string message)
{
	if (msg_.empty())
	{
		return nullptr;
	}
	else
	{
		for (auto sender : msg_)
		{
			if (sender.first == message)
			{
				return sender.second;
			}
		}
		return nullptr;
	}
}

