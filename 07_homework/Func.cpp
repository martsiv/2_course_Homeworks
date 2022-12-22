#include "Func.h"
void ShowAllElements(Device** devices, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		devices[i]->Print();
	}
}
double AveragePrice(Device** devices, int size)
{
	double result = 0;
	for (size_t i = 0; i < size; i++)
	{
		result += devices[i]->GetPrice();
	}
	return result / size;
}
double TotalWeigth(Device** devices, int size)
{
	double result = 0;
	for (size_t i = 0; i < size; i++)
	{
		result += devices[i]->GetWeight();
	}
	return result;
}