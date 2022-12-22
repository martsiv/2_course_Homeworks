#pragma once
#include <iostream>
using namespace std;

class Device
{
private:
	string model;
	double weight;
	string serialNumber;
	double price;
	int power;
protected:
	bool onOff;
public:
	Device(string model, double weight, string serialNumber, double price, int power)
		: model(model), weight(weight), serialNumber(serialNumber), price(price), onOff(0), power(power)
	{ }
	virtual void Print() const;
	virtual void TurnOn();
	virtual void TurnOff();
	virtual void ToDoJob(int hours);
	double GetWeight() const	{	return weight;	}
	double GetPrice() const	{	return price;	}
};