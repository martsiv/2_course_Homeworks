#pragma once
#include <iostream>
#include <string>
#include "CombatVehicle.h"

CombatVehicle** makeArmy(int& size);
void deleteArmy(CombatVehicle** army, int& size);
int Round(CombatVehicle& bm1, CombatVehicle& bm2);
bool ifArmyLoose(CombatVehicle** army, int& size);
