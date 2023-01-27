#pragma once
#include <iostream>
#include <exception>
#include <initializer_list>

using namespace std;

template <typename T>
class Stack
{
private:
	enum { Empty = -1 };

	T* data;
	const int maxSize;
	int top;

public:
	explicit Stack(int size) : maxSize(size)
	{
		data = new T[size] {};
		top = Empty; // no elements
	}
	Stack(const std::initializer_list<T>& list);
	Stack(const Stack& that);
	~Stack()
	{
		delete[] data;
	}
	void Push(T element); // add new item to the top
	T Pop();				 // remove the top item
	T Peek();			 // get the top item
	int GetCount() { return top + 1; }
	void Clear() { top = Empty; }

	bool IsEmpty() const { return top == Empty; }
	bool IsFull() const { return top == maxSize - 1; }

	Stack& operator=(const Stack& stk);
};


template<typename T>
inline Stack<T>::Stack(const std::initializer_list<T>& list) : Stack<T>::Stack(list.size())
{
	int count = 0;
	for (auto& element : list)
	{
		data[count] = element;
		++count;
	}
}

template <typename T>
Stack<T>::Stack(const Stack& that) : maxSize(that.maxSize), top(that.top)
{
	data = new T[maxSize]{};
	for (int i = 0; i < maxSize; ++i)
		this->data[i] = that.data[i];
}
template <typename T>
T Stack<T>::Peek()
{
	if (IsEmpty())
		throw exception("Stack is empty!");

	return data[top];
}
template <typename T>
void Stack<T>::Push(T element)
{
	if (IsFull())
		throw exception("Stack is full!");

	data[++top] = element;	// increment the top element index
	// and set the top element value
}
template <typename T>
T Stack<T>::Pop()
{
	if (IsEmpty())
		throw exception("Stack is empty!");

	return data[top--];
}
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& stk)
{
	T tmp;
	int i = 0;
	for (; i < this->maxSize; i++)
	{
		if (i < stk.maxSize)
			tmp = stk.data[i];
		else
		{
			top = i;
			break;
		}
		this->data[i] = tmp;
	}
	this->top = --i;
	return *this;
}