#pragma once
#include <iostream>
using std::string;
using std::cout;

class CarBody
{
	enum class CarBodyType { Hatchback = 1, Coupe, Sedan, StationWagon, Minivan };
	int numberOfSeats;
	string color;
	CarBodyType carBodyType;
public:
	CarBody(int numberOfSeats = 2, string color = "Black", CarBodyType carBodyType = CarBodyType::Hatchback)
		: numberOfSeats(numberOfSeats), color(color), carBodyType(carBodyType) {}
	string GetType() const
	{
		switch (carBodyType)
		{
		case CarBody::CarBodyType::Hatchback:
			return "Hatchback";
			break;
		case CarBody::CarBodyType::Coupe:
			return "Coupe";
			break;
		case CarBody::CarBodyType::Sedan:
			return "Sedan";
			break;
		case CarBody::CarBodyType::StationWagon:
			return "Station Wagon";
			break;
		case CarBody::CarBodyType::Minivan:
			return "Minivan";
			break;
		default:
			return "";
			break;
		}
	}
	void Show() const
	{
		cout << color << " " << GetType() << ", " << numberOfSeats << " number of seats\n";
	}
};