#include <iostream>
#include <ctime>
#include "func.h"
#include "CombatVehicle.h"
#include "AirDefenseVehicle.h"
#include "ArmoredCar.h"
#include "Tank.h"


int main()
{
	int size1 = 0;
	int size2 = 0;

	static bool isOpened = 0;
	if (!isOpened)
	{
		srand(unsigned(time(0)));
		isOpened = 1;
	}

	CombatVehicle** army1 = makeArmy(size1);
	std::cout << '\n';
	for (int i = 0; i < size1; ++i)
		army1[i]->ShowInfo();
	std::cout << "\n-------------------------------------\n";

	CombatVehicle** army2 = makeArmy(size2);
	std::cout << '\n';
	for (int i = 0; i < size2; ++i)
		army2[i]->ShowInfo();
	std::cout << "\n-------------------------------------\n";

	//rounds
	int rounds = 0;
	while (true)
	{
		//check or some army lost
		bool army1Loose = ifArmyLoose(army1, size1);
		bool army2Loose = ifArmyLoose(army2, size2);

		if (army1Loose && army2Loose)
		{
			std::cout << "Both armies were defeated. A draw!\n";
			break;
		}
		if (army1Loose)
		{
			std::cout << "Army 1 win!\n";
			break;
		}
		if (army2Loose)
		{
			std::cout << "Army 2 win!\n";
			break;
		}

		// choose which combat vehicle will participate in the battle
		int candidateForBattle_Army1;  //index of the combat vehicle
		do
		{
			candidateForBattle_Army1 = rand() % size1;
		} while (army1[candidateForBattle_Army1]->IsDestroyed());
		
		int candidateForBattle_Army2;  //index of the combat vehicle
		do
		{
			candidateForBattle_Army2 = rand() % size2;
		} while (army2[candidateForBattle_Army2]->IsDestroyed());
		
		//result of one battle
		int res;
		if (!(rounds % 2))
			res = Round(*army1[candidateForBattle_Army1], *army2[candidateForBattle_Army2]);
		else
			res = Round(*army2[candidateForBattle_Army2], *army1[candidateForBattle_Army1]);

		if (res)
			std::cout << "In " << rounds + 1 << " round 1 bm win!\n";
		else
			std::cout << "In " << rounds + 1 << " round 2 bm win!\n";
		++rounds;
	}

	deleteArmy(army1, size1);
	deleteArmy(army2, size2);
}


