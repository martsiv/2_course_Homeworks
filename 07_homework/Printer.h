#pragma once
#include <iostream>
#include "Device.h"
using namespace std;

class Printer : public Device
{
private:
	int maxPapers;
	int papers;
	int paperPerHours;
public:
	Printer(string model, double weight, string serialNumber, double price, int power, int maxPapers, int paperPerHours)
		: Device(model, weight, serialNumber, price, power), maxPapers(maxPapers), paperPerHours(paperPerHours), papers(0) { }
	void Print() const override;
	void ToDoJob(int hours) override;
	void AddPaper(int value);
};
