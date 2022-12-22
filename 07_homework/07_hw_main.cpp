#include "Func.h"
#include "Device.h"
#include "Monitor.h"
#include "Printer.h"
#include "Router.h"
#include "TV.h"
int main()
{
	Device device("Robot", 15.2, "3495439RH", 7999.99,  1750);
	device.Print();
	int hours = 5;
	device.ToDoJob(hours);
	device.Print();
	cout << "========Monitor==========\n";
	Monitor monitor("Philips", 3.4, "GF4725792", 4500, 35, 1920, 1200, 4);
	monitor.Print();
	monitor.ConnectDevice();
	monitor.ConnectDevice();
	monitor.ChangeCurrentlyConnectedPort(1);
	monitor.Print();
	monitor.ToDoJob(hours);

	cout << "========Printer==========\n";
	Printer printer("Canon", 4.1, "Jfw38294", 3800, 650, 1800, 600);
	printer.Print();
	printer.AddPaper(1900);
	printer.Print();
	printer.ToDoJob(hours);
	printer.TurnOff();
	printer.Print();

	cout << "========Router==========\n";
	Router router("Asus", 0.7, "23349GHfj", 990, 120, 100);
	router.Print();
	router.AddDevise();
	router.AddDevise();
	router.AddDevise();
	router.Print();
	router.ToDoJob(hours);
	router.TurnOff();
	router.Print();

	cout << "========TV==========\n";
	TV tv("LG", 2.1, "34r9239d", 10700, 250, 80);
	tv.Print();
	tv.TurnOn();
	tv.ChangeChannel(9);
	tv.Print();
	tv.ToDoJob(hours);
	tv.TurnOff();
	tv.Print();

	cout << "\n\n----------Devices-----------\n";
	const int size = 4;
	Device* devices[size] =
	{ &monitor, &printer, &router, &tv };
	ShowAllElements(devices, size);
	cout << "\nAvrage price = " << AveragePrice(devices, size) << "uah\n";
	cout << "\nTotal Weigth = " << TotalWeigth(devices, size) << "kg\n";
	
}