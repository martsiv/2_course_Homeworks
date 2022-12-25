#include <iostream>
#include <fstream>
using namespace std;

class File
{
private:
	string path;
public:
	File(string path) : path(path) {}

	virtual void Display() const
	{
		ifstream fin;
		fin.open(path);
		if (!fin.is_open())
		{
			cout << "Can not open the file " << path << endl;
			cout << "Exit program.\n";
			exit(EXIT_FAILURE);
		}
		double value;
		double sum = 0.0;
		int count = 0;			//к≥льк≥сть прочитаних елемент≥в
		while (fin >> value)	//допоки вв≥д усп≥шний ≥ не дос€гнув EOF
		{
			++count;			//ще один елемент прочитано
			sum += value;		//вирахувати поточну суму
		}
		if (fin.eof())
			cout << "End of file.\n";	//ƒос€гнуто к≥нц€ файлу
		else if (fin.fail())
			cout << "Input aborted due to data mismatch.\n";	//¬в≥д припинено через нев≥дпов≥дн≥сть даних
		else 
			cout << "Input aborted for an unknown reason.\n";	//¬в≥д припинено через нев≥дому причину
		if (count == 0)
			cout << "No data has been processed.\n";	//Ќ≥€к≥ дан≥ не опрацьован≥
		else
		{
			cout << "Items have been read: " << count << endl;
			cout << "Sum: " << sum << endl;
			cout << "Average: " << sum / count << endl;
		}
		fin.close();		//завершити роботу з файлом
	}
	void Clear()
	{

	}
	void AddNewData(string newString)
	{

	}
};

int main()
{

}