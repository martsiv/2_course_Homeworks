#include "Car.h"

void Car::Show()
{
	cout << "--------------------------------\n";
	cout << model << " " << year << "year\n";
	cout << "Registration number: " << number << endl;
	cout << "Car body type: " << GetCarBody() << endl;
	cout << "Transmission " << GetTransmission() << endl;
	cout << "Engine capacity " << engineCapacity << "L\n";
}
void Car::SetTransmission(Transmission val)
{
	transmission = val;
}
void Car::SetEngineCapacity(double val)
{
	engineCapacity = val;
}
std::ostream& operator<< (std::ostream& out, const Car& car)
{
	out << "--------------------------------\n";
	out << car.model << " " << car.year << "year\n";
	out << "Registration number: " << car.number << endl;
	out << "Car body type: " << car.GetCarBody() << endl;
	out << "Transmission " << car.GetTransmission() << endl;
	out << "Engine capacity " << car.engineCapacity << "L\n";
	return out;
}