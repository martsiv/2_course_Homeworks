#include "Router.h"

void Router::Print() const 
{
	Device::Print();
	cout << totalConnectionDevices << '/' << maxConnectionDevices << " devices are connected.\n";
}
void Router::TurnOff() 
{
	Device::TurnOff();
	cout << "All devices were disconnected.\n";
	totalConnectionDevices = 0;
}
void Router::AddDevise()
{
	if (maxConnectionDevices <= totalConnectionDevices)
	{
		cout << "We cannot connect more devices than the limit.\n";
		return;
	}
	cout << "Added a new device\n";
	++totalConnectionDevices;
}
void Router::DeleteDevice()
{
	if (!totalConnectionDevices)
	{
		cout << "No devices are connected to the router.\n";
		return;
	}
	cout << "Deleted one device\n";

	--totalConnectionDevices;
}