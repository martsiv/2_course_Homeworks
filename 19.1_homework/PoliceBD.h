#pragma once
#include <iostream>
#include "Tree.h"
#include "List.h"
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
class Offender		//порушник, містить номер порушника (автомобільний номерний знак) та список закріплених за ним порушень
{
	string carNumber;
	LinkedList<Offence> offences;
public:
	Offender(string carNumber) : carNumber(carNumber) {}
	friend ostream& operator<< (ostream& out, const Offender& Offender)
	{
		out << Offender.carNumber << ":\n";
		Offender.offences.Show();
		return out;
	}
};

class PoliceBD		// База даних порушників, містить порушників і в кожного з них є порушення
{
	
	Tree<Offender*> offenders;

};

