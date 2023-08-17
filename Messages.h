#pragma once
#include <map>
#include "Chat.h"
#include "IObserver.h"

class Messages		//все функции и поля класса доступны только для Chat
{
public:
	virtual ~Messages() {};
	Messages() {};
	std::multimap <std::string, IObserver*> msg_{};
};
	
