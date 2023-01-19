#include "MyDB.h"


MyDB::~MyDB()
{
	for (size_t i = 0; i < size; i++)
	{
		delete user[i];
	}
	delete[] user;
}

void MyDB::add()
{
	cout << "-----------Add new User-----------\n";
	//============================================================
	string firstname;
	while (true)
	{
		cout << "\nEnter firstname: ";
		try
		{
			firstname = GetValidName();
			break;
		}
		catch (const IncorrectName& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}
	//============================================================
	string lastname;
	while (true)
	{
		cout << "\nEnter lastname: ";
		try
		{
			lastname = GetValidName();
			break;
		}
		catch (const IncorrectName& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}
	//============================================================
	int yearOfBirth;
	while (true)
	{
		cout << "\nEnter year of birth: ";
		try
		{
			yearOfBirth = GetValidBirth();
			break;
		}
		catch (const std::exception& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}
	//============================================================
	string phonenumber;
	while (true)
	{
		cout << "\nEnter phone number: ";
		try
		{
			phonenumber = GetValidPhoneNumber();
			break;
		}
		catch (const std::exception& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}
	//============================================================
	string email;
	while (true)
	{
		cout << "\nEnter email: ";
		try
		{
			email = GetValidEmail();
			break;
		}
		catch (const std::exception& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}

	//============================================================
	string cardnumber;
	while (true)
	{
		cout << "\nEnter card number: ";
		try
		{
			cardnumber = GetValidCardNumber();
			break;
		}
		catch (const std::exception& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}

	//============================================================
	int postalcode;
	while (true)
	{
		cout << "\nEnter postal code: ";
		try
		{
			postalcode = GetValidPostalCode();
			break;
		}
		catch (const std::exception& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	}

	++size;
	User** tmp = new User * [size];
	for (size_t i = 0; i < size - 1; i++)
		tmp[i] = user[i];
	tmp[size - 1] = new User(firstname, lastname, yearOfBirth, phonenumber, email, cardnumber, postalcode);;
	delete[] user;
	user = tmp;
}

void MyDB::remove(int index)
{
	if (size <= 0 || index < 0 || size <= index)
		throw out_of_range("Out of the range");
	--size;
	int count = 0;
	User** arr2 = new User * [size];
	for (int i = 0; i < size + 1 && count < size; i++)
	{
		if (i != index)
		{
			arr2[count] = user[i];
			count++;
		}
	}
	delete[] user;
	user = arr2;
}

User& MyDB::find(string name)
{
	for (size_t i = 0; i < size; i++)
	{
		if (0 <= (*user[i]).GetFullname().find(name))
			return *user[i];
	}
}

void MyDB::sort(std::function<bool(string, string)> fcn)
{
	if (size <= 0)
		return;
	bool swapped;
	int counter = 0;
	User* tmp = nullptr;
	do
	{
		swapped = 0;
		for (int j = 0; j < size - 1 - counter; j++)
		{
			if (fcn(user[j]->GetFullname(), user[j + 1]->GetFullname()))
			{
				swapped = 1;
				tmp = user[j];
				user[j] = user[j + 1];
				user[j + 1] = tmp;
			}
		}
		counter++;
	} while (swapped);
}

void User::Show() const
{
	cout << "------------------------\n";
	cout << "Name - " << firstname << " " << lastname << endl;
	cout << "Year of birth - " << yearOfBirth << endl;
	cout << "Phone number - " << phonenumber << endl;
	cout << "E-mail - " << email << endl;
	cout << "Credit card number - " << cardnumber << endl;
	cout << "Postal code number - " << postalindex << endl;
}
