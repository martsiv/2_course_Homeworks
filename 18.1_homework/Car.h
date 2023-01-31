#pragma once
#include <iostream>
#include <string>

enum class CarBody { Sedan = 0, Coupe, Hatchback, Minivan, StationWagon };
enum class Transmission { Mechanical = 0, Automatic, Robotic };

using std::string;
using std::cout;
using std::endl;

class Car
{
	const string number;
	string model;
	int year;
	CarBody carBody;
	Transmission transmission;
	double engineCapacity;
	std::string GetCarBody() const
	{
		switch (CarBody(carBody))
		{
		case CarBody::Sedan:
			return "Sedan";
			break;
		case CarBody::Coupe:
			return "Coupe";
			break;
		case CarBody::Hatchback:
			return "Hatchback";
			break;
		case CarBody::Minivan:
			return "Minivan";
			break;
		case CarBody::StationWagon:
			return "Station Wagon";
			break;
		default:
			return "none";
			break;
		}
	}
	std::string GetTransmission() const
	{
		switch (Transmission(transmission))
		{
		case Transmission::Mechanical:
			return "Mechanical";
			break;
		case Transmission::Automatic:
			return "Automatic";
			break;
		case Transmission::Robotic:
			return "Robotic";
			break;
		default:
			return "none";
			break;
		}
	}
public:
	Car(string number, string model, int year, CarBody carBody, Transmission transmission, double engineCapacity)
		: number(number), model(model), year(year), carBody(carBody), transmission(transmission), engineCapacity(engineCapacity) {}
	string GetNumber() { return number; }
	void Show();
	void SetTransmission(Transmission val);
	void SetEngineCapacity(double val);
	friend std::ostream& operator<< (std::ostream& out, const Car& car);
	friend bool operator== (const Car& c1, const Car& c2) {	return (c1.number == c2.number); }
	friend bool operator< (const Car& c1, const Car& c2) { return (c1.year < c2.year); }
	friend bool operator> (const Car& c1, const Car& c2) { return (c1.year > c2.year); }
};