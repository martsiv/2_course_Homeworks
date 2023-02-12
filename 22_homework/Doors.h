#pragma once

class Doors
{
	int numbers;
public:
	Doors(int numbers = 3) : numbers(numbers) {}
	int GetNumbers() const { return numbers; }
};