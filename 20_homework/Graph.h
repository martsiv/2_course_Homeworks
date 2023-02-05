#pragma once
#include <initializer_list>
using namespace std;

template <typename T>
class Graph
{
private:
	struct Node
	{
		T data;
		Node** relations;
		int relationsSize;

		Node(T data, Node** relations = nullptr, int size = 0)
			: data(data), relations(relations), relationsSize(size) { }

		void AddRelation(Node* node)
		{
			Node** newArr = new Node * [relationsSize + 1];
			for (size_t i = 0; i < relationsSize; i++)
			{
				newArr[i] = relations[i];
			}
			newArr[relationsSize] = node;
			delete[] relations;
			this->relations = newArr;

			++relationsSize;
		}
		void DeleteRelations(Node* node)
		{
			Node** newArr = new Node * [relationsSize - 1];
			for (int i = 0, j = 0; i < relationsSize; i++)
			{
				if (relations[i] != node)
				{
					newArr[i] = relations[i];
					++j;
				}
			}
			delete[] relations;
			this->relations = newArr;

			--relationsSize;
		}
	};

	Node* root;
	Node** nodes;
	int size;

	void AddNodePointer(Node* node)
	{
		Node** newArr = new Node * [size + 1];
		for (size_t i = 0; i < size; i++)
		{
			newArr[i] = nodes[i];
		}
		newArr[size] = node;
		delete[] nodes;
		this->nodes = newArr;

		++size;
	}
	void DeleteNodePointer(Node* node)
	{
		Node** newArr = new Node * [size - 1];
		for (int i = 0, j = 0; i < size; i++)
		{
			if (nodes[i] != node)
			{
				newArr[j] = nodes[i];
				++j;
			}
		}
		delete[] nodes;
		this->nodes = newArr;

		--size;
	}
	Node* FindNode(const T& value) const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (nodes[i]->data == value)
				return nodes[i];
		}

		return nullptr;
	}

public:
	Graph() : root(nullptr), nodes(nullptr), size(0) { }
	~Graph()
	{
		for (size_t i = 0; i < size; i++)
		{
			delete nodes[i];
		}
		delete[] nodes;
	}

	Graph(const Graph& graph)
	{
		root = nullptr;
		Node* item;
		for (size_t i = 0; i < graph.size; i++)
		{
			item = new Node(graph.nodes[i]->data);
			if (!root) root = item;
			AddNodePointer(item);
		}
		for (size_t i = 0; i < size; i++)
		{
			for (size_t k = 0; k < graph.nodes[i]->relationsSize; k++)
			{

				Node* relation = FindNode(graph.nodes[i]->relations[k]->data);
				if (relation == nullptr) continue;

				nodes[i]->AddRelation(relation);
			}
		}
	}
	void Add(const T& data, const initializer_list<T> relations)
	{
		Node* item = new Node(data);

		if (root == nullptr) root = item;

		for (const T& value : relations)
		{
			Node* relation = FindNode(value);
			if (relation == nullptr) continue;

			item->AddRelation(relation);
			relation->AddRelation(item);
		}

		AddNodePointer(item);
	}

	bool Delete(const T& data)
	{
		Node* tmp = FindNode(data);
		if (!tmp || tmp->relationsSize > 1)
			return false;
		tmp->relations[0]->DeleteRelations(tmp);

		DeleteNodePointer(tmp);
		delete tmp;
		return true;
	}
	void Show() const
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << "Node: " << nodes[i]->data << " - ";

			for (size_t k = 0; k < nodes[i]->relationsSize; k++)
			{
				cout << nodes[i]->relations[k]->data << ", ";
			}
			cout << endl;
		}
	}
	void Find(const T& data) const
	{
		Node* tmp = FindNode(data);
		if (!tmp)
		{
			cout << "Not found!\n";
			return;
		}

		cout << "Node: " << tmp->data << " - ";

		for (size_t i = 0; i < tmp->relationsSize; i++)
		{
			cout << tmp->relations[i]->data << ", ";
		}
		cout << endl;
	}
};