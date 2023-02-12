#pragma once
#include <iostream>
using std::cout;
using std::string;

class Engine
{
	enum class EngineType { Diesel = 1, Gasoline, Electricity };
	int capacity;
	EngineType engineType;
public:
	Engine(int capacity = 1000, EngineType engineType = EngineType::Gasoline)
		: capacity(capacity), engineType(engineType) {}
	int GetCapacity() { return capacity; }
	string GetType() const
	{
		switch (engineType)
		{
		case EngineType::Diesel:
			return "Diesel";
		case EngineType::Gasoline:
			return "Gasoline";
		case EngineType::Electricity:
			return "Electricity";
		default:
			return "";
		}
	}
	void Show() const
	{
		cout << GetType() << " " << capacity;
		if (engineType == EngineType::Electricity)
			cout << "kW\n";
		else
			cout << "cm^2\n";
	}
};