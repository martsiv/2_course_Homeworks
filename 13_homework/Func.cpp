#include "Func.h"


string GetValidName()
{
	string name;
	cin >> name;
	if (name.size() < 2)
		throw IncorrectName("The name must be longer than 1 character");
	if (!isupper(name[0]))
		throw IncorrectName("The name must begin with a capital letter");
	return name;
}
int GetValidBirth()
{
	int yearOfBirth;
	cin >> yearOfBirth;
	if (yearOfBirth < 1930 || 2020 < yearOfBirth)
		throw exception("Birth year is invalid");
	else
		cout << "Year of birth success!\n";
	return yearOfBirth;
}
string GetValidPhoneNumber()
{
	string phonenumber;
	cin >> phonenumber;
	int digitCounter = 0;
	int size = phonenumber.size();
	if (size < 13)
		throw exception("The phone number is too small");
	if (!(phonenumber[0] == '+' && phonenumber[1] == '3' && phonenumber[2] == '8'))
		throw exception("The country code is incorrect");
	for (int i = 3; i < size; ++i)
	{
		if (isdigit(phonenumber[i]))
			++digitCounter;
		else if (phonenumber[i] == '-')
			continue;
		if (digitCounter == 1 && phonenumber[i] != '0')
			throw exception("The number is incorrect, there are invalid values");
	}
	if (digitCounter != 10)
		throw exception("The number of digits in the phone number does not match");
	else
		cout << "Phone number success!\n";
	return phonenumber;
}
string GetValidEmail()
{
	string email;
	cin >> email;
	int size = email.size();
	int isAtPosition = -1;
	int isDotAfterAt = -1;
	if (size < 5)
		throw exception("Incorrect email length");
	for (int i = 0; i < size; ++i)
	{
		if ((i < size - 1) && (email[i] == '.') && (email[i + 1] == '.'))
			throw exception("Incorrect format in email");
		if (!(isalnum(email[i]) || email[i] == '@' || email[i] == '.' || email[i] == '_'))
			throw exception("Incorrect character in email");
		if (((0 < isAtPosition) || i == 0) && email[i] == '@')
			throw exception("Incorrect format in email");
		if (i && email[i] == '@')
			isAtPosition = i;
		if (isAtPosition && email[i] == '.' && (isAtPosition < (i + 1)) && (isAtPosition < (i + 1)) != (email.size() - 1))
			isDotAfterAt = i;
	}
	if ((isAtPosition < 0) || (isDotAfterAt < 0) || (isAtPosition == (isDotAfterAt - 1)))
		throw exception("Incorrect format in email");
	else
		cout << "Email success!\n";
	return email;
}
string GetValidCardNumber()
{
	string cardnumber;
	string result;
	cin >> cardnumber;
	int size = cardnumber.size();
	int digitCounter = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (isdigit(cardnumber[i]))
		{
			++digitCounter;
			result += cardnumber[i];
		}
	}
	if (digitCounter != 16)
		throw exception("Incorrect card number length");
	else
		cout << "Card number success!\n";
	return result;
}
int GetValidPostalCode()
{
	string postalindex;
	cin >> postalindex;
	int size = postalindex.size();
	if (size != 5)
		throw exception("Incorrect postal code length");
	if (!(postalindex[0] == '3' && postalindex[1] == '3'))
		throw exception("Invalid postal code");
	else
		cout << "Postal code success!\n";
	return std::stoi(postalindex);
}