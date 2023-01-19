#pragma once
#include <iostream>
#include <string>
using namespace std;

class User
{
	string firstname;
	string lastname;
	int yearOfBirth;
	string phonenumber;
	string email;
	string cardnumber;
	int postalindex;
public:
	User(string firstname, string lastname, int yearOfBirth, string phonenumber, string email, string cardnumber, int postalindex)
		: firstname(firstname), lastname(lastname), yearOfBirth(yearOfBirth), phonenumber(phonenumber), email(email), cardnumber(cardnumber), postalindex(postalindex) {}
	string GetFullname() { return firstname + " " + lastname; }
	void Show() const;
};

