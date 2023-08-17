#include <iostream>
#include "Chat.h"
#include "Messages.h"

Chat::~Chat()
{
	if (!all_users_.empty())
	{
		for (IObserver* user : all_users_)
		{
			delete user;
		}
	}
	if (messages_ != nullptr)
	{
		delete messages_;
	}
}

void Chat::set_User(IObserver* observer)
{
	all_users_.emplace_back(observer);
}

void Chat::attach(IObserver* observer)
{		
	list_observers_.push_back(observer);
	std::cout << "\nYou are logged into the chat! \nIf you want to exit the chat, enter - 4.\n";
}

void Chat::notify(IObserver* sender, char event)
{
	std::cout << "\n\nEnter your message: ";
	std::string message;
	std::cin >> message;

	if (messages_ == nullptr)
	{
		messages_ = new Messages;
	}

	std::list<IObserver*>::iterator iterator = list_observers_.begin();
	if (event == 's')
	{
		std::cout << "Your messages are sending\n";
		while (iterator != list_observers_.end()) {
			(*iterator)->update(message);
			messages_->msg_.insert({ message, sender });
			++iterator;
		}
	}
	else if (event == 'c')
	{
		std::cout << "Enter name or login: ";
		std::string name;
		std::cin >> name;

		while (iterator != list_observers_.end())
		{
			if (((*iterator)->get_name() == name) || ((*iterator)->get_login() == name))
			{
				std::cout << "Your message is sending\n";
				(*iterator)->update(message);
				messages_->msg_.insert({ message, sender });

				//сбросить все символы из потока
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				return;
			}
			++iterator;
		}
		std::cout << "\nSuch user wasn't found! Try agan!";
	}
	//сбросить все символы из потока
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}

void Chat::detach(IObserver* observer)
{
	std::list<IObserver*>::iterator it = list_observers_.begin();
	for (it; it != list_observers_.end(); ++it) {
		if (((*it)->get_login() == observer->get_login()) && ((*it)->get_password() == observer->get_password()))
		{
			list_observers_.erase(it);
			return;
		}		
	}
}

void Chat::display_listObservers()
{
	std::cout << "\nThe list authorized users: \n";
	if (list_observers_.empty())
	{
		std::cout << "No Users!\n";
	}
	else
	{
		for (IObserver* observer : list_observers_)
		{
			std::cout << "name - " << observer->get_name() << ", \tlogin - "
				<< observer->get_login() << "\;\n";
		}
	}
}

bool Chat::is_check_Observer(IObserver* observer, std::string login, std::string password)
{
	if (observer == nullptr)
	{
		return false;
	}
	else
	{
		//проверка логина и пароля
		while (true)
		{
			if ((observer->get_login() == login) && (observer->get_password() == password))
			{
				return true;
			}
			//логическое XOR:
			else if ((observer->get_login() == login || observer->get_password() == password)
				&& !(observer->get_login() == login && observer->get_password() == password))
			{
				std::cout << "\nYour login or password are wrong! Try again.\n";
				std::cout << "If you want to exit click: exit\n";

				std::cout << "\nEnter your username: ";
				std::cin >> login;
				if (login == "exit")
				{
					return false;
				}
				else
				{
					std::cout << "Enter your password: ";
					std::cin >> password;
				}
			}
			else
			{
				return false;
			}
		}
	}
}

IObserver* Chat::find_user(std::string login)
{
	if (all_users_.empty())
	{
		return nullptr;
	}
	else
	{
		std::vector<IObserver*>::iterator user = all_users_.begin();
		while (user != all_users_.end()) {
			if ((*user)->get_login() == login)
			{
				return *user;
			}
			++user;
		}
	}
	return nullptr;
}

