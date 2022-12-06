#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Weapon
{
private:
	int shotRange;
	float caliber;
	int numberOfBullets;
	int maxBullets;
public:
	int Initialize(int range = 0, float caliber = 7.62, int maxSize = 30)
	{
		if (range < 0)
		{
			cerr << "Invalid range!\n";
			return 1;
		}
		if (caliber < 0)
		{
			cerr << "Invalid caliber!\n";
			return 1;
		}
		if (maxSize < 1)
		{
			cerr << "Invalid max number of bullets!\n";
			return 1;
		}
		shotRange = range;
		this->caliber = caliber;
		maxBullets = maxSize;
		numberOfBullets = 0;
		return 0;
	}
	bool Shot()
	{
		if (!numberOfBullets)
			return false;
		numberOfBullets--;
		return true;
	}
	void Recharge()
	{
		numberOfBullets = maxBullets;
	}
	void ShowBullets()
	{
		cout << "You have " << numberOfBullets << "/" <<
			maxBullets << " bullets\n";
	}
	bool Save(string fname)
	{
		ofstream fout;
		fout.open(fname);
		if (!fout)
		{
			cerr << "Error read file\n";
			return 1;
		}
		fout << shotRange << ' ' << caliber << ' ' << numberOfBullets << ' ' << maxBullets;
		fout.close();
		return 0;
	}
	bool Load(string fname)
	{
		ifstream fin;
		fin.open(fname);
		if (!fin)
		{
			cerr << "Error read file\n";
			return 1;
		}
		fin >> shotRange >> caliber >> numberOfBullets >> maxBullets;
	
		fin.close();
		return 0;
	}
};

int verificateNum(int leftRange, int rightRange);
int main()
{
	int range, maxBullets;
	float caliber;	
	Weapon weapon{};
	do
	{
		cout << "Enter the parameters of weapon\n";
		cout << "Enter the range of shot(m): ";
		cin >> range;
		cout << "Enter caliber: ";
		cin >> caliber;
		cout << "Enter max number of bullets: ";
		cin >> maxBullets;
	} while (weapon.Initialize(range, caliber, maxBullets));
	
	int tmp = 1;
	while (tmp)
	{
		weapon.ShowBullets();
		cout << "1 - To shot\n";
		cout << "2 - To recharge\n";
		cout << "0 - To exit\n";
		tmp = verificateNum(0, 2);
		if (tmp == 1)
		{
			if (weapon.Shot())
				cout << "Nice shot!\n";
			else
				cout << "Out of ammo, need to recharge!\n";
			system("PAUSE");
			system("cls");
		}
		else if (tmp == 2)
		{
			weapon.Recharge();
			system("cls");
		}
	}

	cout << "Enter a file name to save weapon settings: ";
	string filename;
	cin >> filename;
	if (weapon.Save(filename))
		return EXIT_FAILURE;

	Weapon weapon2{};
	if (weapon2.Load(filename))
		return EXIT_FAILURE;
	cout << "Weapon2:\n";
	weapon2.ShowBullets();
}

int verificateNum(int leftRange, int rightRange)
{
	int num;
	while (!(cin >> num) || (num < leftRange) || (rightRange < num))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	return num;
}