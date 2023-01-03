#pragma once
#include "CombatVehicle.h"
#include "func.h"

class AirDefenseVehicle : public CombatVehicle
{
private:
	int rangeOfAction;
	int rateOfFire;
	int mobility;	// 1- 10
protected:
	int Attack()
	{
		return (150 + rangeOfAction * (rateOfFire / 10));
	}
	void Defense(int damage)
	{
		health = ((health - damage / mobility) < 0 ? 0 : (health - damage / mobility));
	}
public:
	AirDefenseVehicle(TypeCombatVehicle type, std::string model, int health, int rangeOfAction, int rateOfFire, int mobility)
		: CombatVehicle(type, model, health), rangeOfAction(rangeOfAction), rateOfFire(rateOfFire), mobility(mobility) {}
	void ShowInfo() override
	{
		CombatVehicle::ShowInfo();
		std::cout << "Range of action:\t" << rangeOfAction << std::endl;
		std::cout << "Rate of fire:\t\t" << rateOfFire << std::endl;
		std::cout << "Mobility:\t\t" << mobility << std::endl;
	}
};