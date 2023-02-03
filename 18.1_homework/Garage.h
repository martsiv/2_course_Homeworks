#pragma once
#include <iostream>
#include "Dictionary.h"
#include "Car.h"
template <typename T>
bool FirstBigger(T v1, T v2) { return *v1 > *v2; }
template <typename T>
bool SecondBigger(T v1, T v2) { return *v1 < *v2; }
using namespace std;
class Garage
{
	Dictionary<string, Car*> cars;
	int size;
public:
	Garage() : size(0), cars() {}
	void ShowAllCars() const;
	void AddCar(Car* car);
	bool ChangeParameters(string carNumber);
	void FindCar(string carNumber);
	void RemoveCar(string number);
	bool SortUP();
	bool SortDown();
};

