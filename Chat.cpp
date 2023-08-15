#include <iostream>
#include "Chat.h"


void Chat::attach(IObserver* observer)
{
	all_users_.emplace_back(observer);
	std::cout << "You have been authorized!\n";
	list_observers_.push_back(observer);
	curr_observer_ = observer;
}

IObserver* Chat::log_in()
{	
	std::string login;
	std::cout << "\nEnter your username: ";
	std::cin >> login;

	std::string password;
	std::cout << "Enter your password: ";
	std::cin >> password;

	std::vector<IObserver*>::iterator iterator = all_users_.begin();
	while (iterator != all_users_.end()) {
		if ((*iterator)->check_observer(login, password))
		{
			std::cout << "You have been authorized!\n";
			list_observers_.push_back(*iterator);
			curr_observer_ = *iterator;
			return (*iterator);
		}
		++iterator;
	}
	std::cout << "\nNo such user was found! Please register!\n";
	return nullptr;
}

void Chat::detach(IObserver* observer)
{
	list_observers_.remove(observer);
}

void Chat::display_listObservers()
{
	std::cout << "\nThe list authorized users: \n";
	for (IObserver* observer : list_observers_)
	{
		std::cout << observer->get_dataObserver()["login"] << "\n";
	}
}

void Chat::notify()
{
	std::cout << "notify \n";
}

Chat::~Chat()
{
	if (!all_users_.empty())
	{
		for (IObserver* user : all_users_)
		{
			delete user;
		}
	}
}