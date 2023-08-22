#pragma once

#include <iostream>
#include "Chat.h"
#include "User.h"


class ClientCode
{
public:
	void start();
	bool containsOnlyLettersNum(std::string const  &str);
	User* make_user(Chat* chat);
};

