#pragma once
#include <string>
#include <map>
#include "Chat.h"

class User : public IObserver
{
public:	
	User(Chat* chat);
	virtual ~User() {}
	
	void update(IObserver* sender, std::string message) override;

	std::string& get_name() override { return name_; }
	std::string& get_login() override { return login_; }
	std::string& get_password() override { return password_; }
	int get_userID() override { return user_ID_; }	
	
	//функции для ClientCode	
	User* log_in(Chat* chat);
	void create_message();
	void leave_chat(Chat* chat);
	void display_Messages();

	void set_name(std::string name) { name_ = name; }
	void set_login(std::string login) { login_ = login; }
	void set_password(std::string password) { password_ = password; }
	void set_userID() { user_ID_ = ++static_counter; }
	void set_isAutorization() { is_autorization_ = true; }
	void set_notAutorization() { is_autorization_ = false; }

private:
	Chat* chat_ = nullptr;
	std::string name_{};
	std::string login_{};
	std::string password_{};
	int user_ID_ {0};
	bool is_autorization_{ false };
	std::multimap <IObserver*, std::string> messages_{};

	static int static_counter;	
};


