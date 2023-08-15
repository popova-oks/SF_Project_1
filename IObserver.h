#pragma once
#include <string>
#include <map>

class IObserver {
public:
	virtual ~IObserver() {};
	virtual void update() = 0;

	virtual std::map <std::string, std::string> get_dataObserver() = 0;
	virtual bool check_observer(std::string login, std::string password) = 0;
};
