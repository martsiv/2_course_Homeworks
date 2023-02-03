#pragma once
#include <iostream>
#include <functional>

using namespace std;

// Associative Containers - contain elements without any specific order

template <typename TKey, typename TValue>
class Dictionary
{
	struct Node
	{
		TKey key;
		TValue value;

		Node() { }
		Node(TKey key, TValue value) : key(key), value(value) { }
	};

	Node* data;
	int size;

public:
	Dictionary() : size(0), data(nullptr) { }
	~Dictionary()
	{
		delete[] data;
	}

	TValue& Get(const TKey& key) const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (data[i].key == key)
				return data[i].value;
		}
		throw exception("Key does not exist!");
	}
	TValue& operator[](const TKey& key) const
	{
		return this->Get(key);
	}

	bool IsEmpty() const { return size == 0; }
	void Add(const TKey& key, const TValue& value)
	{
		if (ContainsKey(key)) return;
		Node* newArr = new Node[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			newArr[i] = data[i];
		}
		newArr[size] = Node(key, value);
		delete[] data;
		data = newArr;
		++size;

	}

	void Delete(const TKey& key)
	{
		--size;
		Node* newArr = new Node[size];
		for (size_t i = 0; i < size + 1; i++)
		{
			if (data[i].key != key)
				newArr[i] = data[i];
		}
		delete[] data;
		data = newArr;
	}
	bool ContainsKey(const TKey& key) const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (data[i].key == key) return true;
		}
		return false;
	}
	bool ContainsValue(const TValue& value) const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (data[i].value == value) return true;
		}
		return false;
	}

	void Show() const
	{
		if (IsEmpty()) cout << "Collection is empty!";
		else
		{
			for (size_t i = 0; i < size; i++)
			{
				cout << data[i].key << ": \n" << *(data[i].value) << endl; //used *data!
			}
		}
	}
	void Sort(std::function<bool(TValue, TValue)> fcn)
	{
		bool swapped;
		int counter = 0;
		do
		{
			swapped = 0;
			for (int j = 0; j < size - 1 - counter; j++)
			{
				if (fcn(data[j + 1].value, data[j].value))
				{
					swapped = 1;
					Node tmp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = tmp;
				}
			}
			counter++;
		} while (swapped);
	}
};