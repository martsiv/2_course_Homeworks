#include <iostream>
#include <ctime>
using namespace std;

int GetRandomInt(int leftVal, int RightVal);

class Human
{
private:
	string name;
	int age;
public:
	Human(string name, int age) : name(name), age(age) {}
	virtual ~Human() {}
	virtual void Show() const = 0;
	string GetName() const { return name; }
};

class Tutor : public Human
{
private:
	double price;
	string subject;
	int students;
	const int maxStudents;
public:
	Tutor(string name, int age, double price, string subject, int maxStudents)
		: Human(name, age), price(price), subject(subject), students(0), maxStudents(maxStudents) {}
	void Show() const override;
	int getStudents() const { return students; }
	int AddSudent();
	int DeleteStudent();
};

class Employee : public Human
{
private:
	string company;
	double salary;
public:
	Employee(string name, int age, string position, string company, double salary)
		: Human(name, age), company(company), salary(salary) {}
	virtual void Show() const override = 0;
	void SetSallary(double salary) { (*this).salary = salary; };
	void SetCompany(string company) { (*this).company = company; };
	double GetSalary() const { return salary; }
	virtual void DoWork() = 0;
};

class Scientist : public Employee
{
private:
	string education = "none";
	int IQ = 100;
public:
	Scientist(string name, int age, string position, string company, double salary, string education, int iq)
		: Employee(name, age, position, company, salary), education(education), IQ(iq) {}
	void Show() const override;
	void DoWork() override;
};

class Manager : public Employee
{
private:
	int subordinates = 0;
	int tasks = 0;
public:
	Manager(string name, int age, string position, string company, double salary, int subordinates, int busySubordinates, int tasks)
		: Employee(name, age, position, company, salary), subordinates(subordinates), tasks(tasks) {}
	void Show() const override;
	void AddSubordinates(int nSubordinates);
	void RemoveSubordinates(int nSubordinates);
	int GetSubordinates() const { return subordinates; };
	void AddTask();
	void DoWork() override;
};

class Specialist : public Employee
{
private:
	int experience;
	int workingDaysToNewExperience = 365;
public:
	Specialist(string name, int age, string position, string company, double salary, int experience)
		: Employee(name, age, position, company, salary), experience(experience) {}
	void Show() const override;
	void DoWork() override;
	int GetDaysToNewExperience() { return workingDaysToNewExperience; };
};

class Learner : public Human
{
private:
	string eduInstitution;
public:
	Learner(string name, int age, string eduInstitution)
		: Human(name, age), eduInstitution(eduInstitution) {}
	virtual void Show() const override = 0;
	virtual void ToLearn() const = 0;
};

class SchoolChild : public Learner
{
private:
	int grade;
	const int maxGrade = 11;
public:
	SchoolChild(string name, int age, string eduInstitution, int grade, int maxGrade)
		: Learner(name, age, eduInstitution), grade(grade), maxGrade(maxGrade) {}
	void Show() const override;
	void ToLearn() const override;
	void GoToNextGrade();
};

class Student : public Learner
{
private:
	string groupName;
	int cours;
public:
	Student(string name, int age, string eduInstitution, string groupName, int cours)
		: Learner(name, age, eduInstitution), groupName(groupName), cours(cours) {}
	void Show() const override;
	void ToLearn() const override;
	void GoTonextCours();
};

int main()
{
	int size = 3;
	Human** human = new Human * [size]
	{
		new Tutor("Nik", 33, 500, "Math", 20),
			new Scientist("Joe", 41, "Scientist", "NASA", 20000, "Ph.D", 125),
			new Student("Lina", 18, "LKA", "F-31", 3)
	};
	for (int i = 0; i < size; i++)
	{
		human[i]->Show();
		cout << endl;
		delete human[i];
	}
	delete[] human;
	Employee** employee = new Employee * [size]
	{
		new Specialist("Sam", 31, "Specialist", "UkrGaz", 30000, 12),
			new Scientist("Joe", 41, "Scientist", "NASA", 20000, "Ph.D", 125),
			new Manager("Valeryi", 40, "Manager", "Ukrposhta", 45000, 10, 1, 1)
	};
	for (int i = 0; i < size; i++)
	{
		cout << "Name: " << employee[i]->GetName() << endl;
		cout << "Salary: " << employee[i]->GetSalary() << endl;
		employee[i]->DoWork();
		cout << endl;

		delete employee[i];
	}
	delete[] employee;
}

// --------------- Func -----------------
int GetRandomInt(int leftVal, int RightVal)
{
	srand(unsigned(time(0)));
	return leftVal + rand() % (RightVal - leftVal + 1);
}

// --------------- Human -----------------
void Human::Show() const
{
	cout << name << " have " << age << " years old\n";
}

// --------------- Employee -----------------
void Employee::Show() const
{
	Human::Show();
	cout << "Company " << company << endl;
	cout << "Salary $" << salary << endl;
}

// --------------- Tutor -----------------
void Tutor::Show() const
{
	Human::Show();
	cout << "He is a tutor. The subject is " << subject << endl;
	cout << "The price per hour is $" << price << endl;
	cout << "The number of students tutored: " << students << endl;
}
int Tutor::AddSudent()
{
	if (maxStudents < (students + 1))
	{
		cout << "You take the maximum number of students.\n";
		return -1;
	}
	else
	{
		++students;
		return 0;
	}
}
int Tutor::DeleteStudent()
{
	if (students <= 0)
	{
		cout << "You have no students.\n";
		return -1;
	}
	else
	{
		--students;
		return 0;
	}
}

// --------------- Scientist -----------------
void Scientist::Show() const
{
	Employee::Show();
	cout << "Education " << education << endl;
	cout << "IQ level " << IQ << endl;
}
void Scientist::DoWork()
{
	int changeIQ = GetRandomInt(-3, 3);
	IQ += changeIQ;
	cout << GetName() << " conducted a number of scientific studies, the IQ level " << (0 < changeIQ ? " increased" : (changeIQ != 0 ? " decreased" : " has no changed")) << endl;
	cout << "IQ level = " << IQ << endl;
}

// --------------- Manager -----------------
void Manager::Show() const
{
	Employee::Show();
	cout << "Number of subordinates: " << subordinates << endl;
	cout << "Number of work tasks: " << tasks << endl;
}
void Manager::AddSubordinates(int nSubordinates)
{
	if (0 < nSubordinates)
	{
		cout << "The number of subordinates has been increased by " << nSubordinates << endl;
		subordinates += nSubordinates;
		cout << "The total number of subordinates is " << subordinates << endl;
	}
	else
		cout << "Invalid value received\n";
}
void Manager::RemoveSubordinates(int nSubordinates)
{
	if (nSubordinates <= 0)
	{
		cout << "Invalid value\n";
	}
	else if ((subordinates - nSubordinates) < 0)
		cout << "You don't have that many employees.\n";
	else
	{
		subordinates -= nSubordinates;
		cout << "Removed " << nSubordinates << " subordinates from your command.\n";
	}
}
void Manager::AddTask()
{
	++tasks;
	cout << "Tasks have been added, the total number of tasks is " << tasks << endl;
}
void Manager::DoWork()
{
	if ((0 < subordinates) && (0 < tasks))
	{
		--tasks;
		cout << "Your subordinates have completed tasks from the task list.\n";
	}
	else if ((0 < subordinates) && (!tasks))
	{
		cout << "Your subordinates sat without work because you did not give them tasks.\n";
	}
	else if (!subordinates)
	{
		cout << "You have no subordinates, so you could not cope with any task.\n";
	}
}

// --------------- Specialist -----------------
void Specialist::Show() const
{
	Employee::Show();
	cout << experience << " years of work experience\n";
	cout << "There are " << workingDaysToNewExperience << " days left until the next work experience" << endl;
}
void Specialist::DoWork()
{
	cout << "You have worked one working day.\n";
	if (--workingDaysToNewExperience == 0)
	{
		cout << "Congratulations, your work experience has increased by a year.\n";
		workingDaysToNewExperience = 364;
	}
}

// --------------- Learner -----------------
void Learner::Show() const
{
	Human::Show();
	cout << this->GetName() << " is studying at " << eduInstitution;
}

// --------------- SchoolChild -----------------
void SchoolChild::Show() const
{
	Learner::Show();
	cout << " in the " << grade << "th grade.\n";
}
void SchoolChild::ToLearn() const
{
	cout << "School Child went to class today.\n";
}
void SchoolChild::GoToNextGrade()
{
	if (maxGrade <= grade)
		cout << "You are already studying in the graduating class.\n";
	else
	{
		++grade;
		cout << "You have passed the " << grade << "th grade.\n";
	}
}

// --------------- Student -----------------
void Student::Show() const
{
	Learner::Show();
	cout << " in the 5th year " << cours << endl;
	cout << "Group name: " << groupName << endl;
}
void Student::ToLearn() const
{
	cout << this->GetName() << " visited the pairs today.\n";
}
void Student::GoTonextCours()
{
	++cours;
	cout << "Sam transferred to the " << cours << "th year.\n";
}
