#pragma once
#include <iostream>
#include "Device.h"
using namespace std;

class Router : public Device
{
private:
	int maxConnectionDevices;
	int totalConnectionDevices;
public:
	Router(string model, double weight, string serialNumber, double price, int power, int maxConnectionDevices)
		: Device(model, weight, serialNumber, price, power), maxConnectionDevices(maxConnectionDevices), totalConnectionDevices(0) { }
	void Print() const override;
	void TurnOff() override;
	void AddDevise();
	void DeleteDevice();
};
