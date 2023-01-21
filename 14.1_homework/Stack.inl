//#include "Stack.h"
//
//template<typename T>
//inline Stack<T>::Stack(const std::initializer_list<T>& list) : Stack<T>::Stack(list.size())
//{
//	int count = 0;
//	for (auto& element : list)
//	{
//		data[count] = element;
//		++count;
//	}
//}
//
//template <typename T>
//Stack<T>::Stack(const Stack& that) : size(that.size), top(that.top)
//{
//	data = new T[size] {};
//	for (int i = 0; i < size; ++i)
//		this->data[i] = that.data[i];
//}
//template <typename T>
//T Stack<T>::Peek()
//{
//	if (IsEmpty())
//		throw exception("Stack is empty!");
//
//	return data[top];
//}
//template <typename T>
//void Stack<T>::Push(T element)
//{
//	if (IsFull())
//		throw exception("Stack is full!");
//
//	data[++top] = element;	// increment the top element index
//	// and set the top element value
//}
//template <typename T>
//T Stack<T>::Pop()
//{
//	if (IsEmpty())
//		throw exception("Stack is empty!");
//
//	return data[top--];
//}
//template <typename T>
//Stack<T>& Stack<T>::operator=(const Stack& stk)
//{
//	T tmp;
//	int i = 0;
//	for (; i < this->size; i++)
//	{
//		if (i < stk.size)
//			tmp = stk.data[i];
//		else
//		{
//			top = i;
//			break;
//		}
//		this->data[i] = tmp;
//	}
//	this->top = --i;
//	return *this;
//}