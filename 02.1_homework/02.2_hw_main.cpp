// Група ПД221. Микола Марців. Завдання 2
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Product
{
	string name;
	float weight;
	int cal;
};
class Refrigerator
{
	string model;
	float volume;
	vector<Product> products;
public:
	Refrigerator(string setModel = "No model", float setVolume = 300, unsigned size = 10)
	{
		model = setModel;
		if (setVolume < 1)
			volume = 100;
		else
			volume = setVolume;
		products.reserve(size);
	}
	void PutProduct(string foodName, float setWeight = 1, int setCal = 100)
	{
		int size = products.size();
		products.resize(size + 1);
		products[size].name = foodName;
		if (setWeight < 0)
			products[size].weight = 1;
		else
			products[size].weight = setWeight;
		if (setCal < 0)
			products[size].cal = 1;
		else
			products[size].cal = setCal;
	}
	void TakeProduct(string foodName)
	{
		int size = products.size();
		bool swapped;
		for (size_t i = 0; i < size;)
		{
			swapped = 0;
			if (products[i].name.find(foodName) != std::string::npos)
			{
				for (size_t j = i; j < size - 1; j++)
				{
					products[j] = products[j + 1];
				}
				products.pop_back();
				size--;
				swapped = 1;
			}
			if (!swapped)
				i++;
		}
	}
	void ShowProductList() const
	{
		int size = products.size();
		for (size_t i = 0; i < size; i++)
		{
			cout << "Product #" << i + 1 << endl;
			cout << "Name: " << products[i].name << endl;
			cout << "Weight: " << products[i].weight << endl;
			cout << "Calories: " << products[i].cal << endl << endl;
		}
		//cout << "Capacity = " << products.capacity() << endl;
	}
	void ShowInfo() const
	{
		cout << "========= Refrigerator =========\n";
		cout << "Model: " << model << endl;
		cout << "Volume: " << volume << endl << endl;
	}
	double GetWeight() const
	{
		int size = products.size();
		double totalWeight = 0;
		for (size_t i = 0; i < size; i++)
			totalWeight += products[i].weight;
		return totalWeight;
	}
	const Product* GetMostCaloric() const
	{
		int size = products.size();
		if (!size)
			return nullptr;
		int indexMax = 0;
		for (size_t i = 1; i < size; i++)
		{
			if (products[indexMax].cal < products[i].cal)
				indexMax = i;
		}
		return &products[indexMax];
	}
};

int main()
{
	Refrigerator fridge("Samsung", 320);
	fridge.ShowInfo();
	fridge.PutProduct("Lime", 2, 150);
	fridge.PutProduct("Juice", 0.5, 200);
	fridge.PutProduct("Rice", 3.5, 650);
	fridge.PutProduct("Banana");
	fridge.ShowProductList();
	fridge.TakeProduct("uice");
	fridge.ShowProductList();
	cout << "The total weight of the products is - " << fridge.GetWeight() << "kg.\n";
	const Product* tmp = fridge.GetMostCaloric();
	if (tmp)
	{
		cout << "\nThe most caloric product is - " << tmp->name << endl;
		cout << "It contains " << tmp->cal << "calories.\n";
	}
}