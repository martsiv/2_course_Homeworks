#pragma once
#include <iostream>
using namespace std;

template <typename T>
class PriorityQueue
{
	enum { SIZE = 20 };
	struct Node
	{
		T* item;
		int priority;
	};
	int size = SIZE;
	Node* items;
	int top;
public:
	explicit PriorityQueue(int size);
	PriorityQueue(const PriorityQueue& Q);
	~PriorityQueue() { delete[] items; }
	bool isEmpty() const { return top == 0; }
	bool isFull() const { return top == size; }
	void Enqueue(T* element, int priority); // add new item to the top
	T& Dequeue();				// remove the item with the highest priority value
	const T& Peek();				// get the item with the highest priority value
	void Clear() { top = 0; }
	void Show() const;
	PriorityQueue& operator=(const PriorityQueue& Q);
};

template<typename T>
inline PriorityQueue<T>::PriorityQueue(int size) : size(size), top(0)
{
	items = new Node[size];
}

template<typename T>
inline PriorityQueue<T>::PriorityQueue(const PriorityQueue& Q)
{
	size = Q.size;
	top = Q.top;
	items = new Node[size];
	for (int i = 0; i < top; i++)
		items[i] = Q.items[i];
}

template<typename T>
inline void PriorityQueue<T>::Enqueue(T* element, int priority)
{
	if (isFull())
		throw exception("Queue is full!");

	// index to insert the new item
	int index = 0;

	if (!isEmpty())
	{
		// find position to insert the new item
		for (; index < top; index++)
		{
			if (items[index].priority >= priority) break;
		}

		// move the existing items
		for (int i = top; i > index; --i)
		{
			items[i] = items[i - 1];
		}
	}

	// insert new item to found position
	items[index] = { element, priority };

	++top;
}

template<typename T>
inline T& PriorityQueue<T>::Dequeue()
{
	if (isEmpty())
		throw exception("Queue is empty!");
	
	return *((items[--top]).item);
}

template<typename T>
inline const T& PriorityQueue<T>::Peek()
{
	if (isEmpty())
		throw exception("Queue is empty!");

	return *(items[top - 1].item);
}


template<typename T>
inline void PriorityQueue<T>::Show() const
{
	if (isEmpty())
		throw exception("Priority Queue is empty");

	cout << "Queue: \n";
	for (size_t i = 0; i < top; i++)
	{
		cout << *(items[i].item) << " / " << items[i].priority << endl;
	}
	cout << endl;
}

template<typename T>
inline PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& Q)
{
	if (this == &Q)
		return *this;
	delete[] items;
	size = Q.size;
	top = Q.top;
	items = new Node[size];
	for (int i = 0; i < top; i++)
		items[i] = Q.items[i];
	return *this;
}
