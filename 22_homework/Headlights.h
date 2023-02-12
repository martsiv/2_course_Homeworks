#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Headlights
{
	string company;
	int power;
	int colorTemperature;
public:
	Headlights(string company = "Osram", int power = 5, int colorTemperature = 5500)
		: company(company), power(power), colorTemperature(colorTemperature) {}
	void Show() const
	{
		cout << company << ", power - " << power << "W, temperature color - " << colorTemperature << endl;
	}
	int GetPower() const { return power; }
	int GetTemperature() const { return colorTemperature; }
	string GetCompany() const { return company; }
};