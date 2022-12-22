#include "Monitor.h"

void Monitor::Print() const
{
	Device::Print();
	cout << "Resolution:\t" << resolution.x << "x" << resolution.y << endl;
	cout << "Maximum number of connection ports: " << maxConnectionPorts << endl;
	cout << "Connected devices to ports: " << totalConnectionPorts << endl;
	if (0 < totalConnectionPorts)
		cout << "The port is currently active: " << currentlyConnectedPort << endl;
}
void Monitor::ConnectDevice()
{
	if (maxConnectionPorts <= totalConnectionPorts)
	{
		cout << "Too many devices connected. To connect another one, you must first disconnect one of the already connected ones.\n";
		return;
	}
	++totalConnectionPorts;
	cout << "New device is connected.\n";
	cout << "Free ports for connected " << totalConnectionPorts << "/" << maxConnectionPorts << endl;
	currentlyConnectedPort = totalConnectionPorts;
}
void Monitor::DisconnectDevice()
{
	if (totalConnectionPorts <= 0)
	{
		cout << "This operation could not be performed. No device is connected.\n";
		return;
	}
	--totalConnectionPorts;
	cout << "One device was disconnected from the port.\n";
	cout << "Free ports for connected " << totalConnectionPorts << "/" << maxConnectionPorts << endl;
}
void Monitor::ChangeCurrentlyConnectedPort(int port)
{
	if (totalConnectionPorts <= 0)
	{
		cout << "This operation could not be performed. No device is connected.\n";
		return;
	}
	if (port <= 0 || totalConnectionPorts < port)
	{
		cout << "No device is connected to this port.\n";
		return;
	}
	currentlyConnectedPort = port;
	cout << "The current active port is " << currentlyConnectedPort << endl;
}