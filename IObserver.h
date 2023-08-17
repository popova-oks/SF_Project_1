#pragma once
#include <string>
#include <map>

class IObserver {
public:
	virtual ~IObserver() {};
	virtual void update(std::string message) = 0;

	virtual std::string& get_name() = 0;
	virtual std::string& get_login() = 0;
	virtual std::string& get_password() = 0;
	virtual int get_userID() = 0;
};
