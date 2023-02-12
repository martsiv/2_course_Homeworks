#pragma once
#include <iostream>
using std::string;
using std::cout;

class Wheel
{
	string company;
	string marking;
	int year;
public:
	Wheel(string company = "Michelin", string marking = "205/55R17", int year = 2022)
		: company(company), marking(marking), year(year) { }
	void Show() const
	{
		cout << company << " " << marking << ", " << year << "year\n";
	}
	string GetMarking() const
	{
		return marking;
	}
	string GetCompany() const
	{
		return company;
	}
};