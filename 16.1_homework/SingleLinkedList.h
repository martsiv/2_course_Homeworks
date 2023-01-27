#pragma once
#include <iostream>
#include <functional> //to function short name
using namespace std;

template <typename T>
class List
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
	int size;
	Node* head;
	Node* tail;
public:
	explicit List() : head(nullptr), tail(nullptr), size(0) { }
	~List()	{ Clear(); }
	bool IsEmpty() const { return !size; }
	List(const List& list);
	void AddHead(T data);
	void DeleteHead();
	void AddTail(T data);
	void AddToPosition(int position, T item);
	void DeleteByPosition(int position);
	T& FindByPredicate(std::function<bool(T)> fnc);
	int Replace(T valToChange, T newVal);
	int GetCount() const;
	T GetLast() const;
	T GetFirst() const;
	T GetElementByPosition(int position) const;
	T GetElementByValue(T value) const;
	void Show() const;
	void Clear();
};

template <typename T>
List<T>::List(const List& list) : size(0)
{
	if (!list.size)
		head = tail = nullptr;
	else
	{
		for (Node* i = list.head; i != nullptr; i = i->next)
			AddTail(i->data);
	}
}

template <typename T>
void List<T>::AddHead(T data)
{
	// create new item
	Node* item = new Node;
	item->data = data;	// set data
	item->next = head;	// link with next item

	// set tail if the list is empty
	if (IsEmpty()) tail = item;

	// set new item as a head
	head = item;

	// increase size
	++size;
}

template <typename T>
void List<T>::DeleteHead()
{
	if (IsEmpty()) return;

	// save current head
	Node* temp = head;

	// set new head
	head = head->next;

	// delete previous head item
	delete temp;

	// decrease size
	--size;

	// clear tail the list is empty
	if (IsEmpty()) tail = nullptr;
}

template <typename T>
void List<T>::AddTail(T data)
{
	// create new item
	Node* item = new Node;
	item->data = data;
	item->next = nullptr;

	if (IsEmpty())
		head = item; // set head if the list is empty
	else
		tail->next = item; // link new item with the previous

	// set new item as a tail
	tail = item;

	// increase size
	++size;
}

template <typename T>
void List<T>::AddToPosition(int position, T item)
{
	if (position < 0 || size < position)
		throw exception("Invalid position");
	if (!position)
		AddHead(item);
	else if (size == position)
		AddTail(item);
	else
	{
		Node* newItem = new Node{ item, nullptr };
		Node* tmp = head;
		for (size_t i = 0; i < position - 1; i++)
			tmp = tmp->next;
		newItem->next = tmp->next;
		tmp->next = newItem;
		++size;
	}
}

template <typename T>
void List<T>::DeleteByPosition(int position)
{
	if (position < 0 || size <= position)
		throw exception("Invalid position");
	if (!position)
		DeleteHead();
	else
	{
		Node* tmp = head;
		for (size_t i = 0; i < position - 1; i++)
			tmp = tmp->next;
		Node* tmp2 = tmp->next;
		tmp->next = tmp2->next;
		delete tmp2;
		--size;
	}
}

template <typename T>
T& List<T>::FindByPredicate(std::function<bool(T)> fnc)
{
	Node* tmp = head;
	for (size_t i = 0; i < GetCount(); i++, tmp = tmp->next)
	{
		if (fnc(tmp->data))
		{
			cout << "A value matching the search criteria was found. Value = " << tmp->data << endl
				<< "Return(R) the value to the program or continue the search(othes symbol):\t";
			char choise{};

			cin >> choise;
			cin.clear();
			cin.ignore(255, '\n');
			if (choise == 'r' || choise == 'R')
				return tmp->data;
			else
				continue;
		}
	}
	throw exception("End of the list");
}

template <typename T>
int List<T>::Replace(T valToChange, T newVal)
{
	int counter = 0;
	for (Node* tmp = head; tmp; tmp = tmp->next)
	{
		if (tmp->data == valToChange)
		{
			tmp->data = newVal;
			++counter;
		}
	}
	return counter;
}

template <typename T>
T List<T>::GetFirst() const
{
	if (IsEmpty()) throw range_error("List is empty.");

	return head->data;
}

template <typename T>
int List<T>::GetCount() const
{
	return size;
}

template <typename T>
T List<T>::GetLast() const
{
	if (IsEmpty()) throw range_error("List is empty.");

	return tail->data;
}

template <typename T>
T List<T>::GetElementByPosition(int position) const
{
	if (IsEmpty())
		throw range_error("List is empty");
	if (position < 0 || size <= position)
		throw exception("Invalid position");
	Node* result = head;					//if position #0
	for (int i = 0; i < position; ++i)		//if position #1-n
		result = result->next;
	return result->data;
}
template <typename T>
T List<T>::GetElementByValue(T value) const
{
	if (IsEmpty())
		throw range_error("List is empty");

	Node* result = head;
	while ((result != nullptr) && (result->data != value))
		result = result->next;
	if (!result)
		throw exception("Item not found");
	return result->data;
}

template <typename T>
void List<T>::Show() const
{
	// using while cycle
	/*Node* item = head;
	while (item != nullptr)
	{
		cout << item->data << " ";
		item = item->next;
	}*/

	// using for
	for (Node* i = head; i != nullptr; i = i->next)
	{
		cout << i->data << " ";
	}
	cout << endl;
}

template <typename T>
void List<T>::Clear()
{
	Node* item = head;
	while (item != nullptr)
	{
		Node* next = item->next;
		delete item;
		item = next;
	}
	head = nullptr;
	size = 0;
}