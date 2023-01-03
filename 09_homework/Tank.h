#pragma once
#include "CombatVehicle.h"
#include "func.h"

class Tank : public CombatVehicle
{
private:
	int rechargeTime;
	int shotAccuracy;
	int armorThickness;
protected:
	int Attack() override
	{
		return 100 * shotAccuracy / rechargeTime;
	}
	void Defense(int damage) override
	{
		health = ((health - damage + armorThickness) < 0 ? 0 : (health - damage + armorThickness));
	}
public:
	Tank(TypeCombatVehicle type, std::string model, int health, int rechargeTime, int shotAccuracy, int armorThickness)
		: CombatVehicle(type, model, health), rechargeTime(rechargeTime), shotAccuracy(shotAccuracy), armorThickness(armorThickness) {}
	void ShowInfo() override
	{
		CombatVehicle::ShowInfo();
		std::cout << "Recharge time:\t\t" << rechargeTime << std::endl;
		std::cout << "Shot accuracy:\t\t" << shotAccuracy << std::endl;
		std::cout << "Armor thickness:\t" << armorThickness << std::endl;
	}
};