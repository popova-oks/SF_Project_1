#pragma once
#include <string>
#include <map>
#include "Chat.h"

class User : public IObserver
{
public:	
	User(Chat* chat);
	virtual ~User() {}
	void update(std::string message) override;

	std::string& get_name() { return name_; }
	std::string& get_login() { return login_; }
	std::string& get_password() { return password_; }
	int get_userID() { return user_ID_; }	
	
	User* log_in(Chat* chat);
	void create_message();
	void leave_chat(Chat* chat);

	void set_isAutorization() { is_autorization_ = true; }
	void set_notAutorization() { is_autorization_ = false; }

private:
	Chat* chat_ = nullptr;
	std::string name_{};
	std::string login_{};
	std::string password_{};
	int user_ID_ {0};
	bool is_autorization_{ false };
	std::list <std::string> messages_{};
	static int static_counter;

	void make_user();	
};


