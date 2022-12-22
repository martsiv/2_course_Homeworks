#pragma once
#include <iostream>
#include "Device.h"
using namespace std;

struct Resolution
{
	int x;
	int y;
};
class Monitor : public Device
{
private:
	Resolution resolution;
	int maxConnectionPorts;
	int totalConnectionPorts;
	int currentlyConnectedPort;
public:
	Monitor(string model, double weight, string serialNumber, double price, int power, int resX, int resY, int maxConnectionPorts)
		: Device(model, weight, serialNumber, price, power), resolution({ resX, resY }), maxConnectionPorts(maxConnectionPorts), totalConnectionPorts(0), currentlyConnectedPort(-1) { }
	void Print() const override;
	void ConnectDevice();
	void DisconnectDevice();
	void ChangeCurrentlyConnectedPort(int port);
};
