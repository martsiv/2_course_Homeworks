#include "Garage.h"

void Garage::ShowAllCars() const
{
	cars.Show();
}

void Garage::AddCar(Car* car)
{
	cars.Add(car->GetNumber(), car);
	++size;
}

bool Garage::ChangeParameters(string carNumber)
{
	if (!cars.ContainsKey(carNumber))
	{
		cout << "This car was not found\n";
		return false;
	}
	int menu;
	do
	{
		cout << "1 - Change engine capacity\n"
			<< "2 - Change transmission\n";
		cin >> menu;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
		switch (menu)
		{
		case 1:
			cout << "Enter new engine capacity: ";
			double engineVal;
			cin >> engineVal;
			cars.Get(carNumber)->SetEngineCapacity(engineVal);
			break;
		case 2:
			cout << "Enter new transmission (Mechanical = 0, Automatic = 1, Robotic = 2): ";
			int transmissionVal;

			while (!(cin >> transmissionVal) || (transmissionVal < 0) || (2 < transmissionVal))
			{
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			cars.Get(carNumber)->SetTransmission(Transmission(transmissionVal));
			break;
		default:
			break;
		}
	} while (menu < 1 || 2 < menu);

	return true;
}

void Garage::FindCar(string carNumber)
{
	cars.Get(carNumber)->Show();
}

void Garage::RemoveCar(string number)
{
	cars.Delete(number);
}

bool Garage::SortUP()
{
	if (!size)
		return false;
	cars.Sort(SecondBigger<Car*>);
	return true;
}

bool Garage::SortDown()
{
	if (!size)
		return false;
	cars.Sort(FirstBigger<Car*>);
	return true;
}
