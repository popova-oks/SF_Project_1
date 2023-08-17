#include "ClientCode.h"

void ClientCode::start()
{
	Chat* chat = new Chat();
	User* user = nullptr;
	bool flag = true;

	while (flag)
	{
		if (user == nullptr)
		{
			std::cout << "\nNo current User";
		}
		else
		{
			std::cout << "\nThe current user:"
				<< "\nname - " << user->get_name()
				<< "\nlogin - " << user->get_login()
				<< "\nuser_ID - " << user->get_userID();
		}
		std::cout << "\n\nSelect an action:" << std::endl;
		std::cout << "1 - registration, 2 - log in the chat, 3 - send a message, ";
		std::cout << "\n4 - exit the chat,  5 - quit from the program: ";
		char ch;
		std::cin >> ch;

		switch (ch)
		{
		case '1':
		{
			user = make_user(chat);
			break;
		}
		case '2':
		{
			chat->display_listObservers();
			if (chat->is_Users())
			{
				user = user->log_in(chat);
				user->display_Messages();
			}
			else
			{
				std::cout << "\nUsers were not found!\nYou'll need to register in the chat!\n";
			}			
			break;
		}
		case '3':
		{
			chat->display_listObservers();
			if (user == nullptr)
			{
				std::cout << "\nYou need to log in!";
			}
			else
			{
				if (chat->is_Observes())
				{
					user->create_message();
				}
				else
				{
					std::cout << "\nNo authorized users!\n";
				}				
			}
			break;
		}
		case '4':
		{
			if (user == nullptr)
			{
				std::cout << "\nYou need to log in!";				
			}
			else
			{
				user->leave_chat(chat);	
				user = nullptr;
			}
			break;
		}
		case '5':
		{
			flag = false;
			break;
		}
		default:
		{
			std::cout << "\nTry agan.";
			break;
		}
		}
		//�������� ��� ������� �� ������
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
	std::cout << "\nSee you soon agan! " << std::endl;

	delete chat;
}

User* ClientCode::make_user(Chat* chat)
{
	std::string name;
	std::cout << "\nEnter your name: ";
	std::cin >> name;

	std::string login;
	std::cout << "Enter your username: ";
	std::cin >> login;

	std::string password;
	std::cout << "Enter your password: ";
	std::cin >> password;

	User* user = dynamic_cast<User*> (chat->find_user(login));

	if (user != nullptr)
	{
		std::cout << "\nThis user was registrated!\n";
	}
	else
	{
		user = new User(chat);
		
		user->set_name (name);
		user->set_login(login);
		user->set_password (password);
		user->set_userID ();
		user->set_isAutorization();

		std::cout << "\nHi, You are new User! name - " << user->get_name() << " : " <<"ID - " << user->get_userID();		
	}
	return user;
}