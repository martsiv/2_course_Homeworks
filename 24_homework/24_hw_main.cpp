#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
using namespace std;

struct Time
{
	short h, m, s;
	Time(short h, short m, short s) : h(h), m(m), s(s) {}
};

class Train
{
	int number;
	Time departureTime;
	string destination;
public:
	Train(int number, short h, short m, short s, string destination)
		: departureTime(h, m, s), number(number), destination(destination) {}
	void ChangeTime(short h, short m, short s)
	{
		departureTime.h = h;
		departureTime.m = m;
		departureTime.s = s;
	}
	friend bool operator< (const Train& t1, const Train& t2)
	{
		long long tmp1 = t1.departureTime.s + t1.departureTime.m * 60 + t1.departureTime.h * 3600;
		long long tmp2 = t2.departureTime.s + t2.departureTime.m * 60 + t2.departureTime.h * 3600;
		return tmp1 < tmp2;
	}
	void Show() const
	{
		cout << "Train #" << number << endl;
		cout << "Departude time: " << departureTime.h << ":" << departureTime.m << ":" << departureTime.s << endl;
		cout << "Destination: " << destination << endl;
	}
	friend std::ostream& operator<< (std::ostream& out, const Train& tr)
	{
		out << tr.number << endl;
		out << tr.departureTime.h << "\n" << tr.departureTime.m << "\n" << tr.departureTime.s << endl;
		out << tr.destination << endl;
		return out;
	}
	friend std::istream& operator>> (std::istream& in, Train& tr)
	{
		in >> tr.number;
		in >> tr.departureTime.h;
		in >> tr.departureTime.m;
		in >> tr.departureTime.s;
		in >> tr.destination;
		return in;
	}
	operator int() { return number; }
	friend bool operator== (const Train& t1, const Train& t2)
	{
		return t1.number == t2.number;
	}
	const string& GetDestination() { return destination; }

};

class Railway
{
	vector<Train> trains;
public:
	Railway() {}
	void Add(int number, short h, short m, short s, string destination)
	{
		trains.push_back(Train(number, h, m, s, destination));
	}
	void Add(Train& train)
	{
		trains.push_back(train);
	}
	void Show() const
	{
		for (auto tr : trains)
			tr.Show();
	}
	void FindAndShowByNumber(int num)
	{
		vector<Train>::iterator it = find(trains.begin(), trains.end(), num);
		if (it != trains.end())
		{
			std::cout << "Element found: \n";
			(*it).Show();
		}
		else
			std::cout << "Element not found\n";
	}
	void FindAndChangeTime(int num, short h, short m, short s)
	{
		
		vector<Train>::iterator it = find(trains.begin(), trains.end(), num);
		if (it != trains.end())
			(*it).ChangeTime(h, m, s);
		else
			std::cout << "Element not found\n";
	}
	void Sort()
	{
		sort(trains.begin(), trains.end());
	}
	void FindAndShowByDestination(string dest)
	{
		for (auto tr : trains)
		{
			if (tr.GetDestination() == dest)
				tr.Show();
		}
	}
	void Save()
	{
		string name("railway.txt");
		ofstream fout(name);
		if (!fout)
		{
			cerr << name << " could not be opened for reading!" << endl;
			exit(1);
		}
		for (auto i : trains)
			fout << i << endl;
		fout.close();
	}
	void Load()
	{
		string name("railway.txt");
		ifstream fin(name);
		if (!fin)
		{
			cerr << name << " could not be opened for reading!" << endl;
			exit(1);
		}
		int number;
		short h;
		short m;
		short s;
		string destination;
		while (fin)
		{
			fin >> number;
			fin >> h;
			fin >> m;
			fin >> s;
			fin >> destination;
			if (fin)
				trains.emplace_back(number, h, m, s, destination);
		} 
		fin.close();
	}
};

int main()
{
	Railway railway;
	railway.Show();
	railway.Add(245, 9, 20, 0, "Kyiv");
	railway.Add(215, 16, 10, 0, "Lviv");
	railway.Add(236, 21, 35, 0, "Odesa");
	railway.Add(201, 5, 40, 0, "Lviv");
	railway.Show();
	cout << "\n-------------------------------\n";
	railway.FindAndShowByDestination("Lviv");
	cout << "\n-------------------------------\n";
	railway.FindAndShowByNumber(236);
	railway.FindAndShowByNumber(4);
	cout << "\n-------------------------------\n";
	railway.FindAndChangeTime(215, 05, 05, 05);
	railway.Show();
	cout << "\n-------------------------------\n";
	railway.Sort();
	railway.Show();
	cout << "\nNew vector -------------------------------\n";
	railway.Save();
	Railway railway2;
	railway2.Load();
	railway2.Sort();
	railway2.Show();
}