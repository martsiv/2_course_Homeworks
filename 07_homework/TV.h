#pragma once
#include <iostream>
#include "Device.h"
using namespace std;

class TV : public Device
{
private:
	int allChannels;
	int currentlyChannel;
public:
	TV(string model, double weight, string serialNumber, double price, int power, int allChannels)
		: Device(model, weight, serialNumber, price, power), allChannels(allChannels), currentlyChannel(1) { }
	void Print() const override;
	void ChangeChannel(int channel);
};