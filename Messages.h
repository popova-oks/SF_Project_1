#pragma once
#include <map>
#include "Chat.h"
#include "User.h"

class Messages : private Chat		//все функции и поля класса доступны только для Chat
{
	public:				
	
	
	
	
	
	
	
	
	
	std::multimap <User*, std::string>* _messages;	
};
	
