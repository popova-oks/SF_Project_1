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
	if (list_observers_.empty())
	{
		return;
	}
	else
	{
		std::cout << "\nEnter your message: ";

		//�������� ��� ������� �� ������
		std::cin.clear();
		std::cin.ignore(32767, '\n');

		std::string message;
		//std::cin >> message;
		std::getline(std::cin, message);

		if (messages_ == nullptr)
		{
			messages_ = new Messages;
		}		
		if (event == 's')
		{
			for (IObserver* user : list_observers_)
			{
				if (sender != user)
				{
					user->update(message);
					messages_->msg_.insert({ message, sender });
				}
			}			
			std::cout << "Your messages are sending!\n";			
		}
		else if (event == 'c')
		{
			std::cout << "Enter login to send message: ";
			std::string login;
			std::cin >> login;

			IObserver* user = find_user(login);
			if (user == nullptr)
			{
				std::cout << "\nSuch user wasn't found! Try agan!";
			}
			else
			{
				std::cout << "Your message is sending!\n";
				user->update(message);
				messages_->msg_.insert({ message, sender });
			}			
		}
	}
}

std::string Chat::show_Sender(std::string message)
{
	IObserver* sender = messages_->get_Sender(message);
	std::string str;
	if (sender == nullptr)
	{
		str = "The sender is not found!";		
	}
	else
	{
		str = sender->get_login();
	}
	return str;
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
		//�������� ������ � ������
		while (true)
		{
			if ((observer->get_login() == login) && (observer->get_password() == password))
			{
				return true;
			}
			//���������� XOR:
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

