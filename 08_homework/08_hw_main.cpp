#include <iostream>
#include <fstream>
using namespace std;

class File
{
protected:
	string path;
	string data;
public:
	File(string path) : path(path), data{} {}
	string GetString()
	{
		if (data.size())
			return data;
	}
	virtual void Display() 
	{
		ifstream fin;
		fin.open(path);
		if (!fin.is_open())
		{
			cout << "Can not open the file " << path << endl;
			cout << "Exit program.\n";
			exit(EXIT_FAILURE);
		}
		char ch;
		int count = 0;
		while (fin.get(ch))
		{
			data += ch;
			cout << ch;
			++count;
		}
		if (fin.eof())
			cout << "End of file.\n";
		else if (fin.fail())
			cout << "Input aborted due to data mismatch.\n";
		else
			cout << "Input aborted for an unknown reason.\n";
		if (count == 0)
			cout << "No data has been processed.\n";
		else
			cout << "Items have been read: " << count << endl;

		fin.close();
	}
	void Clear()
	{
		ofstream f;
		f.open(path, ios::out);
		f.close();
		data = "";
	}
	void AddNewData(string newString)
	{
		ofstream fout;
		fout.open(path, ios::app);
		if (!fout.is_open())
		{
			cout << "Can not open the file " << path << endl;
			cout << "Exit program.\n";
			exit(EXIT_FAILURE);
		}
		fout << newString;
		fout.close();
	}

};

class ASCIIFile : public File
{
public:
	ASCIIFile(string name) : File(name) {}
	void Display()  override
	{
		ifstream fin;
		fin.open(path);
		if (!fin.is_open())
		{
			cout << "Can not open the file " << path << endl;
			cout << "Exit program.\n";
			exit(EXIT_FAILURE);
		}
		char ch;
		int count = 0;
		while (fin.get(ch))
		{
			cout << int(ch) << ' ';
			++count;
		}
		if (fin.eof())
			cout << "End of file.\n";
		else if (fin.fail())
			cout << "Input aborted due to data mismatch.\n";
		else
			cout << "Input aborted for an unknown reason.\n";
		if (count == 0)
			cout << "No data has been processed.\n";
		else
			cout << "Items have been read: " << count << endl;

		fin.close();
	}
};

void xor_crypt(string key, string& data)
{
	for (int i = 0; i < data.size(); i++)
		data[i] ^= key[i % key.size()];
}

int main()
{
	string name = "test.txt";
	File file(name);
	file.Display();
	file.AddNewData("Carpe diem ");
	file.Display();

	file.AddNewData("Momento mori.");
	file.Display();
	file.Clear();
	file.AddNewData("Clear!");
	file.Display();
	string toEncrypt = file.GetString();
	cout << "Data to Encrypt - " << toEncrypt << endl;
	string key = "abcd";
	xor_crypt(key, toEncrypt);
	cout << "After encryption:\n";
	cout << toEncrypt << endl;
	xor_crypt(key, toEncrypt);
	cout << "After descryption:\n" << toEncrypt << endl;

	ASCIIFile file2(name);
	file2.Display();


}