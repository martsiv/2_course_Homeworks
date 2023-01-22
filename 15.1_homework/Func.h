#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
enum class Position { Guest = 1, Admin, Manager, Director };

std::string currentDateTime();
string GetPosition(int position);
int verificateNum(int leftRange, int rightRange);