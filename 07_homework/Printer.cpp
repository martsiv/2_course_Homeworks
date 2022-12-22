#include "Printer.h"

void Printer::Print() const
{
	Device::Print();
	cout << "The amount of paper in the printer:\t" << papers << '/' << maxPapers << endl;
	cout << "The printer prints at a speed of " << paperPerHours << " pages per hour\n";
}
void Printer::ToDoJob(int hours) 
{
	Device::ToDoJob(hours);
	int paperConsumption = hours * paperPerHours;
	if (papers <= paperConsumption)
	{
		cout << "During the work, you used up all the paper.\n";
		papers = 0;
	}
	else
	{
		cout << papers - paperConsumption << " sheets of paper were used.\n";
		papers -= paperConsumption;
		cout << "The amount of paper in the printer:\t" << papers << '/' << maxPapers << endl;
	}
}
void Printer::AddPaper(int value)
{
	if (value < 0)
		return;
	else if (maxPapers <= value)
		papers = maxPapers;
	else
		papers = value;
}