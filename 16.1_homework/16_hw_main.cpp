#include <iostream>
#include "SingleLinkedList.h"
#include "Stack.h"

bool IsEven(long num)
{
	if (!(num % 2))
		return true;
	return false;
}


int main()
{
	List<long> list;

	list.AddHead(6);
	list.AddHead(2);
	list.AddHead(10);
	list.AddHead(55);
	list.AddHead(87);

	list.Show();
	cout << "-----------------------\n";
	List<long> list2(list);
	list2.Show();
	list2.AddTail(336);
	list2.Show();
	int size = list2.GetCount();
	cout << "Get size " << size << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << "Get elemetn by position  " << i << " " << list2.GetElementByPosition(i) << endl;
	}
	try
	{
		cout << "Get element by value 55: ";
		cout << list2.GetElementByValue(55) << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	cout << "\nAdd 18 to position 3\n";
	list2.AddToPosition(3, 18);
	list2.Show();

	cout << "\nAdd 11 to position 0\n";
	list2.AddToPosition(0, 11);
	list2.Show();

	cout << "\nAdd 22 to position 1\n";
	list2.AddToPosition(1, 22);
	list2.Show();

	size = list2.GetCount();
	cout << "\nAdd 19 to position size\n";
	list2.AddToPosition(size, 18);
	list2.Show();

	cout << "\nAdd 18 to position 3\n";
	list2.AddToPosition(3, 18);
	list2.Show();

	cout << "Delete position 9:\n";
	list2.DeleteByPosition(9);
	list2.Show();

	cout << "\nSize = " << list2.GetCount() << endl;
	cout << "Delete position 0:\n";
	list2.DeleteByPosition(0);
	list2.Show();

	int tmp = list2.Replace(18, 11);
	cout << "\nFind element with value 18 and replace with value 11\n"
		<< "Replaced elements:" << tmp << endl;
	list2.Show();

	try
	{
		cout << "Find by predicate. If (number / 2 = 0)\n ";
		cout << "Result: " << list2.FindByPredicate(IsEven) << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	cout << "Clear list2\n";
	list2.Clear();
	cout << "Show list2:\n";
	list2.Show();

	Stack stack1(10);
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	stack1.push(4);
	cout << "\n Stack ------------------------\n"
		<< "Size of Stack: " << stack1.StckCount() << endl;
	long testStack;
	while (stack1.pop(testStack))
		cout << testStack << endl;
}