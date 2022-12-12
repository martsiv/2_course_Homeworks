#include <iostream>
#include <fstream>
#include <ctime>
#include <functional>

using namespace std;

bool sortUP(long n1, long n2) { return (n2 < n1); }
bool sortDOWN(long n1, long n2) { return (n1 < n2); }
bool minElement(long n1, long n2) { return (n2 < n1); }
bool maxElement(long n1, long n2) { return (n1 < n2); }

class Array
{
private:
	long* arr;
	int size;
	const long BUF = 50;
public:
	Array() { arr = nullptr; size = 0; }
	Array(int size)
	{
		this->size = (size < 0) ? 0 : size;

		if (size <= 0)
		{
			size = 0;
			arr = nullptr;
		}
		else
		{
			arr = new long[size] {};
		}
	}
	Array(const Array& other)
	{
		this->size = other.size;
		this->arr = new long[size];
		for (size_t i = 0; i < size; i++)
			this->arr[i] = other.arr[i];
	}
	~Array()
	{
		if (arr == nullptr || !size)
			return;
		delete[] arr;
		arr = nullptr;
		size = 0;
	}
	void fillRandom()
	{
		static bool isOpen = 0;
		if (!isOpen)
		{
			srand(unsigned(time(0)));
			isOpen = 1;
		}
		int left = -10;
		int right = 10;
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = left + rand() % (right - left + 1);
		}
	}
	void fillKeyboard()
	{
		cout << "-------- Enter " << size << " elements --------\n";
		for (size_t i = 0; i < size; i++)
		{
			cout << "Enter the " << i + 1 << " element: ";
			while (!(cin >> arr[i]))
			{
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
		}
	}
	void fillDefault(long defaultNember)
	{
		for (size_t i = 0; i < size; i++)
			arr[i] = defaultNember;
	}
	void show()
	{
		cout << "========= Array =========\n";
		for (size_t i = 0; i < size; i++)
		{
			cout << '#' << i << " - " << arr[i] << '\n';
		}
		cout << endl;
	}
	void addElement(long num)
	{
		size++;
		long* tmp = new long[size];
		for (size_t i = 0; i < size - 1; i++)
			tmp[i] = arr[i];
		tmp[size - 1] = num;
		delete[] arr;
		arr = tmp;
	}
	void deleteElementByValue(long num)
	{
		if (size <= 0)
			return;
		bool isDelete = 0;
		int b = 0;
		long* tmp = new long[size];
		for (int i = 0; i < size; i++)
		{
			if (arr[i] != num)
			{
				tmp[b] = arr[i];
				++b;
			}
		}
		delete[] arr;
		size = b;
		arr = new long[size];
		for (int i = 0; i < size; i++)
			arr[i] = tmp[i];
		delete[] tmp;
	}
	void deleteElementByIndex(int index)
	{
		if (size <= 0 || index < 0 || size <= index)
			return;
		size--;
		int count = 0;
		long* arr2 = new long[size];
		for (int i = 0; i < size + 1 && count < size; i++)
		{
			if (i != index)
			{
				arr2[count] = arr[i];
				count++;
			}
		}
		delete[] arr;
		arr = arr2;
	}
	void sort(std::function<bool(long, long)> fcn)
	{
		if (size <= 0)
			return;
		bool swapped;
		int counter = 0;
		long tmp;
		do
		{
			swapped = 0;
			for (int j = 0; j < size - 1 - counter; j++)
			{
				if (fcn(arr[j], arr[j + 1]))
				{
					swapped = 1;
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
			counter++;
		} while (swapped);
	}
	long getMinMax(std::function<bool(long, long)> fcn)
	{
		if (size <= 0)
			return 0;
		else if (size == 1)
			return arr[0];
		long MinMax = arr[0];
		for (size_t i = 1; i < size; i++)
		{
			if (fcn(MinMax, arr[i]))
				MinMax = arr[i];
		}
		return MinMax;
	}
	void inputData(string filename)
	{
		ifstream fin;
		fin.open(filename);
		if (!fin.is_open())
		{
			cout << "We can't open the file!\n";
			cout << "Exit program.\n";
			exit(EXIT_FAILURE);
		}
		long* tmp_arr = new long[BUF] {};
		int counter = 0;
		while (fin >> tmp_arr[counter] && counter < BUF)
			++counter;
		if (fin.eof())
			cout << "\nEnd of the file.\n";
		else if (fin.fail())
			cout << "\nError. Not correct data\n";
		else
			cout << "\nError. Unknown reason\n";
		if (!counter)
			cout << "\nNon data\n";
		else
		{
			cout << "\nElements in the file - " << counter << endl;
			if (arr)
				delete[] arr;
			arr = new long[counter];
			size = counter;
			for (size_t i = 0; i < size; i++)
				arr[i] = tmp_arr[i];
		}
		delete[] tmp_arr;
		fin.close();
	}
	void outputData(string filename)
	{
		ofstream fout;
		fout.open(filename);
		if (!fout.is_open())
		{
			cout << "We can't open the file!\n";
			return;
		}
		for (size_t i = 0; i < size; i++)
			fout << arr[i] << ' ';
		fout.close();
	}
};

int main()
{
	Array myArray(5);
	myArray.show();
	cout << "\tFill array by default number (we set 8)\n";
	myArray.fillDefault(8);
	myArray.show();
	cout << "\n\tFill array from the keyboard\b";
	myArray.fillKeyboard();
	myArray.show();
	cout << "\n\tFill array random\b";
	myArray.fillRandom();
	myArray.show();
	cout << "\n\tAdd two element (8, -7)\n";
	myArray.addElement(8);
	myArray.addElement(-7);
	myArray.show();
	cout << "\n\tDelete element by value(8)\n";
	myArray.deleteElementByValue(8);
	myArray.show();
	cout << "\n\tDelete element by index(3)\n";
	myArray.deleteElementByIndex(3);
	myArray.show();
	cout << "\n\tBubble sort by growth\n";
	myArray.sort(sortUP);
	myArray.show();
	cout << "\n\tBubble sort by descending\n";
	myArray.sort(sortDOWN);
	myArray.show();
	cout << "Minimal value = " << myArray.getMinMax(minElement) << endl;
	cout << "Maximal value = " << myArray.getMinMax(maxElement) << endl;
	string filename = "test.txt";
	cout << "\n\tResult is saved to a file\n";
	myArray.outputData(filename);

	cout << "--------- New array ---------\n";
	Array myArr2(3);
	myArr2.show();
	myArr2.inputData(filename);
	myArr2.show();


}