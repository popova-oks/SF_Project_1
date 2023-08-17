#pragma once
#include <vector>
#include <list>
#include "ISubject.h"
#include "IObserver.h"

class Messages;

class Chat : public ISubject
{
public:
	Chat(){}
	virtual ~Chat();
	void set_User(IObserver* observer) override;
	void attach (IObserver* observer) override;	
	void detach (IObserver* observer) override;
	void notify(IObserver* sender, char event) override;
	bool is_check_Observer(IObserver* observer, std::string login, std::string password) override;
	IObserver* find_user(std::string login) override;
	std::string show_Sender(std::string message) override;

	//функции для ClientCode
	bool is_Users() { return !all_users_.empty(); }
	bool is_Observes() { return !list_observers_.empty(); }
	void display_listObservers();	

private:
	std::vector <IObserver*> all_users_{};
	std::list<IObserver*> list_observers_{};
	Messages* messages_ = nullptr;
};
