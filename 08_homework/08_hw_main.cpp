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
		int count = 0;			//������� ���������� ��������
		while (fin >> value)	//������ ��� ������� � �� �������� EOF
		{
			++count;			//�� ���� ������� ���������
			sum += value;		//���������� ������� ����
		}
		if (fin.eof())
			cout << "End of file.\n";	//��������� ���� �����
		else if (fin.fail())
			cout << "Input aborted due to data mismatch.\n";	//��� ��������� ����� ������������ �����
		else 
			cout << "Input aborted for an unknown reason.\n";	//��� ��������� ����� ������� �������
		if (count == 0)
			cout << "No data has been processed.\n";	//ͳ�� ��� �� ����������
		else
		{
			cout << "Items have been read: " << count << endl;
			cout << "Sum: " << sum << endl;
			cout << "Average: " << sum / count << endl;
		}
		fin.close();		//��������� ������ � ������
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