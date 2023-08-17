#pragma once
#include <map>
#include "Chat.h"
#include "IObserver.h"

class Messages		//все функции и поля класса доступны только для Chat
{
public:
	virtual ~Messages() {};
	Messages() {};
	IObserver* get_Sender(std::string message);
	std::multimap <std::string, IObserver*> msg_{};
};
	
