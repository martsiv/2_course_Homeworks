#include <iostream>
#include "Func.h"
#include "FileToPrint.h"
#include "PriorityQueue.h"
#include "Stack.h"


int main()
{
	PriorityQueue<FileToPrint> Printer(20);

	string name;
	int position;
	char choise{};
	while (true)
	{
		if (Printer.isFull())
		{
			cout << "The printer buffer is full. Documents cannot be added to the queue.\n";
			break;
		}
		cout << "Add new document? (y, n): ";
		cin >> choise;
		cin.clear();
		cin.ignore(255, '\n');
		if (choise == 'y' || choise == 'Y')
		{
			cout << "Enter the name: ";
			getline(cin, name);
			cout << "Enter the position: ";
			position = verificateNum(1, 4);
			Printer.Enqueue(new FileToPrint(name, position), position);
		}
		else if (choise == 'N' || choise == 'n')
			break;
		try
		{
			Printer.Show();
		}
		catch (const std::exception& ex)
		{
			cout << "Error: " << ex.what() << endl;
		}
		system("PAUSE");
		system("cls");
	}

	cout << "\nNow the printer prints all documents by priority...\n";
	Stack<FileToPrint*> PrintStatistics(20);
	try
	{
		do 
		{
			cout << Printer.Peek() << endl;
		} while (PrintStatistics.push(&Printer.Dequeue()));
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	cout << "Statistic:\n";
	FileToPrint* tmp;
	while(PrintStatistics.pop(tmp)) 
	{
			cout << *tmp << " " << tmp->GetDate() << endl;
	}
}