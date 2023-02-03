#include <iostream>
#include <string>
#include "PoliceBD.h"
using namespace std;

int main()
{
	PoliceBD policeDB;
	string num1 = "BK7505AM";
	string num2 = "BM9506AA";
	string num3 = "AM3749BH";
	policeDB.AddEntry(num1, "desc1");
	policeDB.AddEntry(num3, "desc1");
	policeDB.AddEntry(num3, "desc2");
	policeDB.AddEntry(num2, "desc1");
	policeDB.AddEntry(num2, "desc2");
	policeDB.AddEntry(num2, "desc3");
	policeDB.AddEntry(num1, "desc2");
	cout << "Print data base:\n";
	policeDB.PrintDB();
	cout << "Find by number " << num2 << endl;
	policeDB.PrintByNumber(num2);
	cout << "Print by the range:\n";
	policeDB.PrintByRange(num3, num2);
}