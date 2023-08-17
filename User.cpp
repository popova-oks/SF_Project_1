#include <iostream>
#include "User.h"
#include "Chat.h"

User::User(Chat* chat)
	: chat_(chat)
{	
	std::cout << "\nHi, You are new User \"" << ++User::static_counter << "\".";
	user_ID_ = User::static_counter;
	make_user();
	chat_->set_User(this);
	chat->attach(this);
	set_isAutorization();
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

User* User::log_in(Chat* chat)
{
	std::string login;
	std::cout << "\nEnter your username: ";
	std::cin >> login;

	std::string password;
	std::cout << "Enter your password: ";
	std::cin >> password;

	User* user = dynamic_cast<User*> (chat->find_user(login));
	if (user == nullptr)	
	{
		std::cout << "\nSuch user wasn't found! You'll need to register in the chat!\n";
		return nullptr;
	}
	else
	{		
		if (chat->is_check_Observer(user, login, password))
		{
			if (user->is_autorization_)
			{
				std::cout << "\nYou are login!\n ";
			}
			else
			{
				chat->attach(user);
			}
			return user;
		}
		else
		{
			std::cout << "\nTry again!\n ";
			return nullptr;
		}		
	}
}

void User::create_message() {
	chat_->display_listObservers();

	char event;
	while (true)
	{
		std::cout << "\nEnter an action: s - send att all, c - chose some user, q - quit: ";		
		std::cin >> event;

		if (event == 'q')
		{
			//сбросить все символы из потока
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			return;
		}
		else if (event == 's' || event == 'c')
		{
			chat_->notify(this, event);
		}		
		else
		{
			std::cout << "\nTry agan!\n";
		}
		//сбросить все символы из потока
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}	
}

void User::update(std::string message)
{
	messages_.push_back(message);
}

void User::leave_chat(Chat* chat)
{
	chat->detach(this);
	set_notAutorization();
	std::cout << "\nYou are detached from the chat!\n";
}

int User::static_counter = 0;