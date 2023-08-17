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
			user = new User(chat);
			break;
		}
		case '2':
		{
			chat->display_listObservers();
			if (chat->is_Users())
			{
				user = user->log_in(chat);
			}
			else
			{
				std::cout << "\nUsers were not found!\nYou'll need to register in the chat!\n";
			}			
			break;
		}
		case '3':
		{
			if (user == nullptr)
			{
				std::cout << "\nYou need to log in!";
			}
			else
			{
				user->create_message();
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
