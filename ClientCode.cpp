#include "ClientCode.h"

void ClientCode::start()
{
	Chat* chat = new Chat();
	User* user = nullptr;
	bool flag = true;

	while (flag)
	{
		if (user != nullptr)
		{
			std::cout << "\nThe current observer:"
				<< "\nname - " << user->get_name()
				<< "\nlogin - " << user->get_login()
				<< "\nuser_ID - " << user->get_userID();
		}
		std::cout << "\n\nSelect an action:" << std::endl;
		std::cout << "1 - registration, 2 - authorization, 3 - send a message, ";
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
			user = dynamic_cast <User*> (chat->log_in());
			break;
		}
		case '3':
		{
			std::cout << "message \n";
			//user->send_message();
			break;
		}
		case '4':
		{
			user->leave_chat(chat);		//Õ≈ –¿¡Œ“¿≈“! »— Àﬁ◊≈Õ»≈!!!!
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
		//Ò·ÓÒËÚ¸ ‚ÒÂ ÒËÏ‚ÓÎ˚ ËÁ ÔÓÚÓÍ‡
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
	std::cout << "\nSee you soon agan! " << std::endl;

	delete chat;
}
