#include <iostream>
#include "User.h"
#include "Chat.h"

User::User(Chat* chat)
	: chat_(chat)
{	
	std::cout << "\nHi, You are new User \"" << ++User::static_counter << "\".";
	user_ID_ = User::static_counter;
	make_user();
	chat->attach(this);
}

void User::make_user()
{
	std::cout << "\nEnter your name: ";
	std::cin >> name_;
	std::cout << "Enter your username: ";
	std::cin >> login_;
	std::cout << "Enter your password: ";
	std::cin >> password_;
}

void User::update()
{
	std::cout << "update \n";
}

void User::leave_chat(Chat* chat)
{
	chat->detach(this);
	set_notAutorization();
	std::cout << "\nYou are detached from the chat!\n";
}

bool User::check_observer(std::string login, std::string password)
{
	if (login_ == login && password_ == password)
	{
		set_isAutorization();
		return true;
	}
	else
	{
		return false;
	}
}

std::map<std::string, std::string> User::get_dataObserver()
{	
	if (this != nullptr)
	{
		std::map<std::string, std::string> data_user;
		data_user.insert(std::make_pair("name", get_name()));
		data_user.insert(std::make_pair("login", get_login()));
		data_user.insert(std::make_pair("password", get_password()));
		return data_user;
	}
	return std::map<std::string, std::string>();
}

int User::static_counter = 0;