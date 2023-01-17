#include <iostream>
#include <fstream>
#include <ctime>
#include <functional>
#include <exception>
#include <string>
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
		if (size <= 0)
			throw exception("Invalid size");
		else if (index < 0 || size <= index)
			throw exception("Invalid index");

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
			throw exception("There are no elements in the array to sort");
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
			throw exception("There are no elements in the array to find min/max value");
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
			throw exception("We can't open the file!\n");
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
			throw exception("We can't open the file!\n");
		}
		for (size_t i = 0; i < size; i++)
			fout << arr[i] << ' ';
		fout.close();
	}
	Array& operator++()
	{
		for (int i = 0; i < size; i++)
			++arr[i];
		return *this;
	}
	Array& operator--()
	{
		for (int i = 0; i < size; i++)
			--arr[i];
		return *this;
	}

	Array operator-() const
	{
		Array tmp(size);
		for (size_t i = 0; i < size; i++)
		{
			tmp.arr[i] = -arr[i];

		}
		return tmp;
	}
	friend std::ostream& operator<< (std::ostream& out, const Array& other)
	{
		for (int i = 0; i < other.size; i++)
			out << other.arr[i] << endl;
		return out;
	}
	friend std::istream& operator>> (std::istream& in, Array& other)
	{
		for (int i = 0; i < other.size; i++)
		{
			cout << "Enter " << i + 1 << " element: ";
			in >> other.arr[i];
		}
		return in;
	}
	Array& operator=(const Array& other)
	{
		if (this == &other)
			return *this;
		delete[] arr;
		size = other.size;
		if (other.arr)
		{
			arr = new long[size];
			for (int i = 0; i < size; ++i)
				arr[i] = other.arr[i];
		}
		else
			arr = nullptr;
		return *this;
	}

	operator double()
	{
		double result = 0;
		for (size_t i = 0; i < size; i++)
			result += arr[i];
		return result;
	}
	Array operator+(const Array& other)
	{
		int new_size = (size < other.size ? other.size : size);
		Array tmp(new_size);
		for (int i = 0; i < tmp.size; ++i)
			tmp.arr[i] = (i < size ? arr[i] : 0) + (i < other.size ? other.arr[i] : 0);
		return tmp;
	}
};

int main()
{
	Array myArray(5);
	myArray.show();
	cout << "\tFill array by default number (we set 8)\n";
	myArray.fillDefault(8);
	myArray.show();
	cout << "\n\tFill array from the keyboard\n";
	myArray.fillKeyboard();
	myArray.show();
	cout << "\n\tFill array random\n";
	myArray.fillRandom();
	myArray.show();
	cout << "\n\tAdd two element (8, -7)\n";
	myArray.addElement(8);
	myArray.addElement(-7);
	myArray.show();
	cout << "\n\tDelete element by value(8)\n";
	myArray.deleteElementByValue(8);
	myArray.show();
	//=================================================
	cout << "\n\tDelete element by index\n";
	int index;
	do
	{
		cout << "Enter the index (q - quit): ";
		cin >> index;
		if (!cin)
		{
			cin.clear();
			if (cin.get() == 'q')
			{
				cout << "Next function\n";
				break;
			}
			while (cin.get() != '\n')
				continue;
			cout << "Incorrect input\n";
			continue;
		}
		try
		{
			myArray.deleteElementByIndex(index);
			cout << "Deleted successful\n";
			myArray.show();
		}
		catch (const std::exception& ex)
		{
			cout << "Message: " << ex.what() << endl;
		}
	} while (true);

	myArray.show();
	//=================================================
	cout << "\n\tBubble sort by growth\n";
	try
	{
		myArray.sort(sortUP);
	}
	catch (const std::exception& ex)
	{
		cout << "Message: " << ex.what() << endl;
	}
	myArray.show();
	//=================================================
	cout << "\n\tBubble sort by descending\n";
	try
	{
		myArray.sort(sortDOWN);
	}
	catch (const std::exception& ex)
	{
		cout << "Message: " << ex.what() << endl;
	}
	myArray.show();
	//=================================================
	cout << "Minimal value\n";
	try
	{
		cout << "Minimal value = " << myArray.getMinMax(minElement) << endl;
	}
	catch (const std::exception& ex)
	{
		cout << "Message: " << ex.what() << endl;
	}
	//=================================================
	cout << "Maximal value\n";
	try
	{
		cout << "Maximal value = " << myArray.getMinMax(maxElement) << endl;
	}
	catch (const std::exception& ex)
	{
		cout << "Message: " << ex.what() << endl;
	}
	//=================================================
	string filename;
	char menu;
	cout << "Save array to file? (y, n)\n";
	while (cin >> menu && (menu == 'y' || menu == 'Y'))
	{
		cout << "Enter the file name(name.txt): ";
		cin >> filename;
		try
		{
			myArray.outputData(filename);
			cout << "\n\tResult is saved to a file\n";
			break;
		}
		catch (const std::exception& ex)
		{
			cout << "Message: " << ex.what() << endl;
			cout << "Would you like to try with a different file name?\n";
		}
	}
	//=================================================

	cout << "--------- New array ---------\n";
	Array myArr2(3);
	myArr2.show();

	cout << "Download data from a file? (y, n)\n";
	while (cin >> menu && (menu == 'y' || menu == 'Y'))
	{
		cout << "Enter the file name(name.txt): ";
		cin >> filename;
		try
		{
			myArr2.inputData(filename);
			cout << "\n\tSuccessfully\n";
			break;
		}
		catch (const std::exception& ex)
		{
			cout << "Message: " << ex.what() << endl;
			cout << "Would you like to try with a different file name (y, n)?\n";
		}
	}
	myArr2.show();
	cout << "\n ++Array:\n";
	++myArr2;
	myArr2.show();
	cout << "\n --Array:\n";
	--myArr2;
	myArr2.show();
	cout << "Enter Array2\n";
	cin >> myArr2;
	cout << "-Array2 = \n" << -myArr2 << endl;
	cout << "Array1 + (Array2) = \n" << (myArray + myArr2) << endl;
	cout << "double(Array2) = " << double(myArr2) << endl;
} 