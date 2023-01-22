#pragma once
#include <iostream>
#include "Func.h"
using namespace std;
class FileToPrint
{
	string name;
	int position;
	string date;
public:
	FileToPrint(string name, int position) : name(name), position(position), date(currentDateTime()) {}
	const string& GetDate() { return date; }
	int GetPosition() { return position; }
	friend std::ostream& operator<< (std::ostream& out, const FileToPrint& point);
};

