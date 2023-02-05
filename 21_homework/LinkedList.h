#pragma once
#include <iostream>
#include <exception>
using namespace std;

template <typename T>
class LinkedList
{
private:
	struct Node
	{
		T data;		// value of the item
		Node* next;	// pointer to the next item 
		Node* prev; // pointer to the previous item

		Node(T data, Node* next = nullptr, Node* prev = nullptr)
			: data(data), next(next), prev(prev) { }
	};
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList() : head(nullptr), tail(nullptr), size(0) { }
	~LinkedList() { Clear(); }
	bool IsEmpty() const { return size == 0; }
	void AddHead(const T& data);
	void DeleteHead();
	void AddTail(const T& data);
	void DeleteTail();
	void InsertItem(const T& data, int index);
	void Reverse();
	void DeleteByIndex(int index);
	const T& GetFirst() const;
	T& GetFirst();
	const T& GetLast() const;
	T& GetLast();
	int GetCount() const;
	void Show() const;
	void Clear();
	T& GoThroughAndReturn();	//Go through the list and return the selected value
};

template <typename T>
void LinkedList<T>::AddHead(const T& data)
{
	// create new item
	Node* item = new Node(data, head);
	//item->data = data;	// set data
	//item->next = head;	// link with next item
	//item->prev = nullptr; // no previous item

	// set tail if the list is empty
	if (IsEmpty()) tail = item;
	else head->prev = item;

	// set new item as a head
	head = item;

	// increase size
	++size;
}

template <typename T>
void LinkedList<T>::DeleteHead()
{
	if (IsEmpty()) return;

	// save current head
	Node* temp = head;

	// set new head
	head = head->next;

	// delete old head item
	delete temp;

	// decrease size
	--size;

	// clear tail the list is empty
	if (IsEmpty()) tail = nullptr;
	// remove link with the previous item
	else head->prev = nullptr;
}

template <typename T>
void LinkedList<T>::AddTail(const T& data)
{
	// create new item
	Node* item = new Node(data, nullptr, tail);
	/*item->data = data;
	item->next = nullptr;
	item->prev = tail;*/

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
void LinkedList<T>::DeleteTail()
{
	if (IsEmpty()) return;

	// save current tail
	Node* temp = tail;

	// set new head
	tail = tail->prev;

	// delete old tail item
	delete temp;

	// decrease size
	--size;

	// clear tail the list is empty
	if (IsEmpty()) head = nullptr;
	// remove link with the previous item
	else tail->next = nullptr;
}

template <typename T>
void LinkedList<T>::InsertItem(const T& data, int index)
{
	if (index < 0 || index > size) throw out_of_range("Index is out of the range!");
	if (index == size) { AddTail(data); return; }
	if (index == 0) { AddHead(data); return; }

	// find item by index
	Node* current = head;
	for (int i = 0; i < index; ++i)
	{
		current = current->next;
	}

	// create new item
	Node* item = new Node(data, current, current->prev);
	/*item->data = data;
	item->next = current;
	item->prev = current->prev;*/

	// link previous item with the new item
	current->prev->next = item;

	// link current item with the new item
	current->prev = item;

	// increase size
	++size;
}

template <typename T>
void LinkedList<T>::Reverse()
{
	LinkedList<T>* newList = new LinkedList<T>;
	int size = GetCount();
	for (size_t i = 0; i < size; i++)
	{
		newList->AddHead(this->GetFirst());
		this->DeleteHead();
	}
	this->head = newList->head;
	this->tail = newList->tail;
	this->size = size;
}

template <typename T>
void LinkedList<T>::DeleteByIndex(int index)
{
	if (index < 0 || index >= size) throw out_of_range("Index is out of the range!");
	if (index == size - 1) { DeleteTail(); return; }
	if (index == 0) { DeleteHead(); return; }
	Node* current = head;
	for (int i = 0; i < index; ++i)
	{
		current = current->next;
	}
	current->prev->next = current->next;
	current->next->prev = current->prev;
	delete current;
	--size;
}

template <typename T>
const T& LinkedList<T>::GetFirst() const
{
	if (IsEmpty()) throw exception("List is empty.");

	return head->data;
}

template <typename T>
T& LinkedList<T>::GetFirst()
{
	if (IsEmpty()) throw exception("List is empty.");

	return head->data;
}

template <typename T>
const T& LinkedList<T>::GetLast() const
{
	if (IsEmpty()) throw exception("List is empty.");

	return tail->data;
}

template <typename T>
T& LinkedList<T>::GetLast()
{
	if (IsEmpty()) throw exception("List is empty.");

	return tail->data;
}

template <typename T>
int LinkedList<T>::GetCount() const
{
	return size;
}

template <typename T>
void LinkedList<T>::Show() const
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
void LinkedList<T>::Clear()
{
	Node* item = head;
	while (item != nullptr)
	{
		Node* next = item->next;
		delete item;
		item = next;
	}
	head = tail = nullptr;
	size = 0;
}

template<typename T>
inline T& LinkedList<T>::GoThroughAndReturn()
{
	char choise;
	Node* tmp = head;
	while (tmp)
	{
		cout << tmp->data << endl;
		cout << "Is right data? (y, n) ";
		cin >> choise;
		cin.clear();
		cin.ignore(255, '\n');
		if (toupper(choise) == 'Y')
			return tmp->data;
		else if (toupper(choise) == 'N')
			tmp = tmp->next;
	}
	throw exception("Didn`t found");
}
