#pragma once
#include <iostream>
using namespace std;

class Offence		//порушення, містить номер порушника (автомобільний номерний знак) та опис порушення
{
	string carNumber;
	string descriprion;
public:
	Offence(string carNumber, string descriprion) : carNumber(carNumber), descriprion(descriprion) {}
	void SetDescription(string descriprion) { descriprion = descriprion; }
	string GetCarNumber() const { return carNumber; }
	string GetDescription() const { return descriprion; }
	friend ostream& operator<< (ostream& out, const Offence& Offence)
	{
		out << Offence.descriprion;
		return out;
	}
};