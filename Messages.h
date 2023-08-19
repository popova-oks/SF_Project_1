#pragma once
#include <map>
#include "Chat.h"
#include "IObserver.h"

class Messages
{
public:
	Messages(){};
	~Messages(){};	
	void set_message(IObserver* sender, std::string message);
private:
	std::multimap <IObserver*, std::string> msg_{};
};
	
