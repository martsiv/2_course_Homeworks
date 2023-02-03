#pragma once
#include <iostream>
#include "Offence.h"
#include "List.h"
using namespace std;

class Offender		//порушник, містить номер порушника (автомобільний номерний знак) та список закріплених за ним порушень
{
	string carNumber;
	LinkedList<Offence> offences;
public:
	Offender(string carNumber) : carNumber(carNumber) {}
	void Print() const { offences.Show(); }
	operator std::string() { return carNumber; }
	void AddOffence(string offence)
	{
		Offence tmp(carNumber, offence);
		offences.AddTail(tmp);
	}
	friend ostream& operator<< (ostream& out, const Offender& Offender);
	friend bool operator< (const Offender& Offender1, const Offender& Offender2) { return Offender1.carNumber < Offender2.carNumber; }
	friend bool operator<= (const Offender& Offender1, const Offender& Offender2) { return Offender1.carNumber <= Offender2.carNumber; }
	friend bool operator> (const Offender& Offender1, const Offender& Offender2) { return Offender1.carNumber > Offender2.carNumber; }
	friend bool operator>= (const Offender& Offender1, const Offender& Offender2) { return Offender1.carNumber >= Offender2.carNumber; }
	friend bool operator== (const Offender& Offender1, const Offender& Offender2) { return Offender1.carNumber == Offender2.carNumber; }
	friend bool operator!= (const Offender& Offender1, const Offender& Offender2) { return Offender1.carNumber != Offender2.carNumber; }
};

ostream& operator<< (ostream& out, const Offender& Offender)
{
	out << Offender.carNumber << ":\n";
	Offender.offences.Show();
	return out;
}