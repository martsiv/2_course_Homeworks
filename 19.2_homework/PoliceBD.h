#pragma once
#include <iostream>
#include "Tree.h"
#include "List.h"
#include "Offence.h"
#include "Offender.h"
using namespace std;

class PoliceBD		// База даних порушників, містить порушників і в кожного з них є порушення
{
	Tree<Offender> offenders;
public:
	void PrintDB() const { offenders.ShowFromLeft(); }
	void AddEntry(string carNumber, string description);
	void PrintByNumber(string number);
	void PrintByRange(string numberLvalue, string numberRvalue);
};

void PoliceBD::AddEntry(string carNumber, string description)
{
	if (offenders.IsEmpty() || !offenders.Find(Offender(carNumber)))
		offenders.Add(Offender(carNumber));
	offenders.Find(Offender(carNumber))->AddOffence(description);
}

void PoliceBD::PrintByNumber(string number)
{
	Offender* tmp = offenders.Find(number);
	if (tmp)
		cout << *tmp << endl;
}

void PoliceBD::PrintByRange(string numberLvalue, string numberRvalue)
{
	if (numberRvalue < numberLvalue)
	{
		string tmp = numberLvalue;
		numberLvalue = numberRvalue;
		numberRvalue = tmp;
	}

	offenders.ShowByRange(Offender(numberLvalue), Offender(numberRvalue));
}