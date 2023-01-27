#pragma once
#include <iostream>

//template <typename T>
class Stack
{
	const int maxSize;
	class Node
	{
	public:
		long item;
		Node* next;
		Node(const long& i, Node* next = nullptr) :item(i), next(next) { }
	};
	int currentSize = 0;
	Node* top;
	Node* tail;
protected:
	void AddTail(const long& item);
public:
	explicit Stack(int size) : top(nullptr), tail(nullptr), maxSize(size) {}
	~Stack();
	Stack(const Stack& st);
	bool IsEmpty() { return currentSize == 0; }
	bool isfull() { return currentSize == maxSize; }
	int StckCount() const { return currentSize; }
	bool push(const long& item);
	bool pop(long& item);
	bool peak(long& item);
};

//template <typename T>
//Stack<T>::~Stack()
Stack::~Stack()
{
	Node* temp;
	while (top != nullptr)      // while queue is not yet empty
	{
		temp = top;       // save address of front item
		top = top->next;// reset pointer to next item
		delete temp;        // delete former front
	}
}

//template <typename T>
//Stack<T>::Stack(const Stack<T>& st) : maxSize(st.maxSize), currentSize(0)
Stack::Stack(const Stack& st) : maxSize(st.maxSize), currentSize(0)
{
	for (Node* i = st.top; i; i = i->next)
		AddTail(i->item);
}

//template <typename T>
//void Stack<T>::AddTail(const T& item)
void Stack::AddTail(const long& item)
{
	Node* tmp = new Node{ item, nullptr };
	if (IsEmpty())
		top = tmp;
	else
		tail->next = tmp;
	tail = tmp;
	++currentSize;
}

//template <typename T>
//bool Stack<T>::push(const T& item)
bool Stack::push(const long& item)
{
	if (isfull())
		return false;
	Node* addItem = new Node(item, top);
	currentSize++;
	if (IsEmpty()) tail = addItem;
	top = addItem;
	return true;
}

//template <typename T>
//bool Stack<T>::pop(T& item)
bool Stack::pop(long& item)
{
	if (IsEmpty()) return false;
	item = top->item;
	Node* temp = top;
	top = top->next;
	delete temp;
	--currentSize;
	if (IsEmpty()) tail = nullptr;
	return true;
}

//template <typename T>
//bool Stack<T>::peak(T& item)
bool Stack::peak(long& item)
{
	if (IsEmpty())
		return false;
	item = top->item;
	return true;
}