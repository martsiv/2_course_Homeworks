#pragma once
#include "CombatVehicle.h"
#include "func.h"

class ArmoredCar : public CombatVehicle
{
private:
	int numberOfWeapons;
	int speed;
protected:
	int Attack() override
	{
		return 50 * numberOfWeapons;
	}
	void Defense(int damage) override
	{
		health = ((health - damage + speed / 2) < 0 ? 0 : (health - damage + speed / 2));
	}
public:
	ArmoredCar(TypeCombatVehicle type, std::string model, int health, int numberOfWeapons, int speed)
		: CombatVehicle(type, model, health), numberOfWeapons(numberOfWeapons), speed(speed) {}
	void ShowInfo() override
	{
		CombatVehicle::ShowInfo();
		std::cout << "Number of weapons:\t" << numberOfWeapons << std::endl;
		std::cout << "Speed:\t\t\t" << speed << std::endl;
	}
};

