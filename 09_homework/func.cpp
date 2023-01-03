#include "func.h"
#include "AirDefenseVehicle.h"
#include "ArmoredCar.h"
#include "Tank.h"
#include "CombatVehicle.h"

std::string ReturnTypeName(TypeCombatVehicle name)
{
	if (name == TypeCombatVehicle::Tank)
		return "Tank";
	else if (name == TypeCombatVehicle::ArmoredCar)
		return "Armored Car";
	else if (name == TypeCombatVehicle::AirDefenseVehicle)
		return "Air Defense Vehicle";
	else
		return "none";
}
CombatVehicle** makeArmy(int& size)
{
	static bool isOpened = 0;
	if (!isOpened)
	{
		srand(unsigned(time(0)));
		isOpened = 1;
	}
	size = 5 + rand() % (10 - 5 + 1);
	CombatVehicle** army = new CombatVehicle * [size];
	for (size_t i = 0; i < size; i++)
	{
		int type = rand() % 3;
		std::cout << "-----------" << i + 1 << '/' << size << "-----------\n";
		std::cout << "Enter the model of the " << ReturnTypeName(TypeCombatVehicle(type)) << " : ";
		std::string model;
		while (!(std::getline(std::cin, model)) || (model.size() < 1))
			continue;

		if (TypeCombatVehicle(type) == TypeCombatVehicle::Tank)
			army[i] = new Tank{ TypeCombatVehicle(type), model, (50 + rand() % (200 - 50 + 1)), (rand() % 201), (rand() % 201), (rand() % 201) };
		else if (TypeCombatVehicle(type) == TypeCombatVehicle::ArmoredCar)
			army[i] = new ArmoredCar{ TypeCombatVehicle(type), model, (50 + rand() % (150 - 50 + 1)), (1 + rand() % 10), (10 + rand() % (180 - 10 + 1)) };
		else if (TypeCombatVehicle(type) == TypeCombatVehicle::AirDefenseVehicle)
			army[i] = new AirDefenseVehicle{ TypeCombatVehicle(type), model, (50 + rand() % (100 - 50 + 1)), (1 + rand() % (600 - 1 + 1)), (1 + rand() % 50), (1 + rand() % 201) };
	}
	return army;
}
void deleteArmy(CombatVehicle** army, int& size)
{
	for (size_t i = 0; i < size; i++)
		delete army[i];
	delete[] army;
	size = 0;
}
int Round(CombatVehicle& bm1, CombatVehicle& bm2)
{
	while (true)
	{
		bm2.Defense(bm1.Attack());
		if (bm2.IsDestroyed())
			return true;
		bm1.Defense(bm2.Attack());
		if (bm1.IsDestroyed())
			return false;
	}
}

bool ifArmyLoose(CombatVehicle** army, int& size)
{
	bool armyLoose = 1;
	for (size_t i = 0; i < size; i++)
	{
		if (!army[i]->IsDestroyed())
		{
			armyLoose = 0;
			break;
		}
	}
	return armyLoose;
}
