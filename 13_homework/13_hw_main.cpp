#include "Class_User.h"
#include "MyDB.h"
#include "Func.h"
bool sortUP(string n1, string n2) { return (n2 < n1); }
bool sortDOWN(string n1, string n2) { return (n1 < n2); }
int main()
{
	MyDB database;
	database.add();
	database.add();
	int size = database.GetSize();
	for (size_t i = 0; i < size; i++)
		database.Show(i);
	User* tmpUser = &database.find("Fred");
	(*tmpUser).Show();
	database.sort(sortUP);
	for (size_t i = 0; i < size; i++)
		database.Show(i);
	try
	{
		database.remove(0);
	}
	catch (const std::out_of_range& ex)
	{
		cout << "Message: " << ex.what() << endl;
	}
	size = database.GetSize();
	for (size_t i = 0; i < size; i++)
		database.Show(i);
}
