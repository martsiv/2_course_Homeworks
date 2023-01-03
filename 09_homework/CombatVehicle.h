#pragma once
#include <iostream>
#include <string>

enum class TypeCombatVehicle { Tank, ArmoredCar, AirDefenseVehicle };
std::string ReturnTypeName(TypeCombatVehicle name);


class CombatVehicle
{
private:
	TypeCombatVehicle type;
	std::string model;
protected:
	int health;
	virtual int Attack() = 0;
	virtual void Defense(int damage) = 0;
public:
	CombatVehicle(TypeCombatVehicle type, std::string model, int health) : type(type), model(model), health(health) {}
	bool IsDestroyed() { return (!health ? true : false); }
	virtual void ShowInfo()
	{
		std::cout << "----==== " << ReturnTypeName(type) << " - " << model << " ====----\n";
		std::cout << "Health:\t\t\t" << health << std::endl;
	}

	friend int Round(CombatVehicle& bm1, CombatVehicle& bm2);
};