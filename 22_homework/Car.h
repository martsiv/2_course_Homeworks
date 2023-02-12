#pragma once
#include <iostream>
#include "CarBody.h"
#include "Doors.h"
#include "Engine.h"
#include "Headlights.h"
#include "Transmission.h"
#include "Wheel.h"
using namespace std;

class Car
{
	string name;
	int year;
	Engine engine;
	CarBody carBody;
	Wheel* wheels;
	int wheelsNum;
	Doors doors;
	Transmission transmission;
	Headlights headlights;

public:
	Car(string name = "Ford Focus", int year = 2022, int wheelsNum = 4)
		: name(name), year(year), wheelsNum(wheelsNum)
	{
		wheels = new Wheel[wheelsNum];
	}
	~Car()
	{
		delete[] wheels;
	}
	void Show() const
	{
		cout << " ----------- " << name << " " << year << " ----------- \n";
		carBody.Show();
		cout << doors.GetNumbers() << " doors\n";
		cout << "Engine:\n";
		engine.Show();
		cout << "Wwheels:\n";
		for (int i = 0; i < wheelsNum; i++)
			wheels[i].Show();
		cout << "Transmission:\n";
		transmission.Show();
		cout << "Headlights:\n";
		headlights.Show();
	}
};