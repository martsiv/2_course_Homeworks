#include "Device.h"
void Device::Print() const
{
	cout << "Model:\t\t- " << model << endl;
	cout << "Weight:\t\t- " << weight << "kg\n";
	cout << "Power:\t\t- " << power << "W\n";
	cout << "Serial number:\t- " << serialNumber << endl;
	cout << "Price:\t\t- " << price << "uah.\n";
	cout << "Device is " << (onOff ? "on" : "off") << endl;
}
void Device::TurnOn()
{
	onOff = 1;
	cout << "Device is on\n";
}
void Device::TurnOff()
{
	onOff = 0;
	cout << "Device is off\n";
}
void Device::ToDoJob(int hours)
{
	TurnOn();
	int energyConsumption = power * hours;
	cout << "The device worked for " << hours << " hours and consumed " << energyConsumption << " watts of electricity\n";
}