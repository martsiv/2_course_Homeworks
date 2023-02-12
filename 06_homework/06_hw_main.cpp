#include <iostream>
using namespace std;

class Animal
{
private:
	string kind;
	int speed;
	float weight;
	string habitat;
	bool move;
public:
	Animal(string kind = "", int speed = 0, float weight = 0, string habitat = "") 
		: kind(kind), speed(speed), weight(weight), habitat(habitat), move(0) {}

	void Move()
	{
		move = true;
		cout << kind << " moves at a speed of up to " << speed << "m/s.\n";
	}
	void Stop()
	{
		move = false;
		cout << kind << " has stopped and now its speed is 0 m per hour.\n";
	}
	void Show() const
	{
		cout << "Kind - " << kind << endl;
		cout << "Speed - " << speed << "m/s\n";
		cout << "Weight - " << weight << "kg\n";
		cout << "Habitat - " << habitat << "\n";
	}

};
class Bird : public Animal
{
private:
	int flightHeight;
	float wingspan;
public:
	void Show()
	{
		Animal::Show();
		cout << "Flight height - " << flightHeight << "m\n";
		cout << "Wingspan - " << wingspan << "m\n";
	}

};
class Reptile : public Animal
{
private:
	float tailSize;
	string color;
public:
	void Show()
	{
		Animal::Show();
		cout << "Tail size - " << tailSize << "cm\n";
	}
};
class Fish : public Animal
{
private:
	bool scales;
	int habitatDepth;
public:
	void Show()
	{
		Animal::Show();
		if (scales)
			cout << "This species has scales\n";
		else
			cout << "This species does not have scales\n";
		cout << "It can dive to a depth of " << habitatDepth << "m\n";
	}
};
class Sparrow : public Bird
{
private:
	int flockSize;
public:
	void Show()
	{
		Bird::Show();
		cout << "A member of a flock of about " << flockSize << " birds\n";
	}
};
class Iguanna : public Reptile
{
private:
	int age;
public:
	void Show()
	{
		Reptile::Show();
		cout << "The age - " << age << endl;
	}
};
class Carp : public Fish
{
private:
	string regionOfOrigin;
public:
	void Show()
	{
		Fish::Show();
		cout << "Region of origin - " << regionOfOrigin << endl;
	}
};
int main()
{
	Animal lion("Lion", 2200, 120, "Savanna");
	lion.Move();
	lion.Stop();
	lion.Show();
}