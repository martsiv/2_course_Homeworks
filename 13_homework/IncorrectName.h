#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class IncorrectName : public logic_error
{
public:
	IncorrectName(string message) : logic_error(message) {}
	const char* what() const override
	{
		return logic_error::what();
	}
};