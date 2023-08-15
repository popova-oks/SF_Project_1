#pragma once
#include <vector>
#include <list>
#include "ISubject.h"
#include "IObserver.h"

class Chat : public ISubject
{
public:
	Chat(){}
	virtual ~Chat();
	void attach (IObserver* observer) override;	
	void detach (IObserver* observer) override;
	void notify() override;

	//void send_message();	
	IObserver* log_in();
	void display_listObservers();

private:
	std::vector <IObserver*> all_users_{};
	std::list<IObserver*> list_observers_{};
	IObserver* curr_observer_ = nullptr;
};
