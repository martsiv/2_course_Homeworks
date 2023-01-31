#include <iostream>
#include <string>
#include "Car.h"
#include "Garage.h"
using namespace std;


int main()
{
	string carNumber = "BK3849AO";
	Car renaultMegan(carNumber, "Renault Megan", 2017, CarBody::Hatchback, Transmission::Automatic, 1.8);
	Car volkswagenGolf("BK8492HA", "Volkswagen Golf", 2014, CarBody::StationWagon, Transmission::Robotic, 1.4);
	Garage garage;
	garage.AddCar(&renaultMegan);
	garage.AddCar(&volkswagenGolf);
	garage.ShowAllCars();

	cout << "\nSort down\n";
	garage.SortDown();
	garage.ShowAllCars();

	cout << "\nSort Up\n";
	garage.SortUP();
	garage.ShowAllCars();

	cout << "Find car by number: " << carNumber << endl;
	garage.FindCar(carNumber);

	garage.ChangeParameters(carNumber);
	garage.FindCar(carNumber);

	cout << "Remove car by number: " << carNumber << endl;
	garage.RemoveCar(carNumber);
	garage.ShowAllCars();
}