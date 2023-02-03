#pragma once
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Tree
{
private:
	struct Node
	{
		/*Node* parent;*/
		T data;
		Node* left;
		Node* right;

		Node(T data, Node* l = nullptr, Node* r = nullptr) : data(data), left(l), right(r) { }
	};

	Node* root;

	void Add(const T& value, Node*& root)
	{
		if (root == nullptr)
			root = new Node(value);
		else if (value > root->data)
			Add(value, root->right);
		else if (value < root->data)
			Add(value, root->left);
	}
	void ShowLKP(Node* root) const
	{
		if (root == nullptr) return;

		//cout << " ( ";
		ShowLKP(root->left);
		cout << root->data << " ";
		ShowLKP(root->right);
		//cout << " ) ";
	}
	void ShowPKL(Node* root) const
	{
		if (root == nullptr) return;

		//cout << " ( ";
		ShowPKL(root->right);
		cout << root->data << " ";
		ShowPKL(root->left);
		//cout << " ) ";
	}
	bool Find(const T& value, const Node* root)
	{
		if (!root)
			return false;
		if (value == root->data)
			return true;
		if (value < root->data)
			return Find(value, root->left);
		if (root->data < value)
			return Find(value, root->right);
	}
	void ShowMax(const Node* root)
	{
		if (!root)
			return;
		if (!root->right)
			cout << root->data;
		else
			ShowMax(root->right);
	}
	void ShowMin(const Node* root)
	{
		if (!root)
			return;
		if (!root->left)
			cout << root->data;
		else
			ShowMin(root->left);
	}
	void DeleteTree(Node*& root)
	{
		if (root == nullptr) return;
		DeleteTree(root->left);
		DeleteTree(root->right);
		delete root;
	}
	void CtorCopyHelp(const Node* another)
	{
		if (another == nullptr) return;
		Add(another->data);
		CtorCopyHelp(another->left);
		CtorCopyHelp(another->right);
	}
	void printPathsRecur(Node* node, T path[], int pathLen)
	{
		if (node == NULL)
			return;

		/* append this node to the path array */
		path[pathLen] = node->data;
		pathLen++;

		/* it's a leaf, so print the path that lead to here */
		if (node->left == NULL && node->right == NULL)
		{
			printArray(path, pathLen);
		}
		else
		{
			/* otherwise try both subtrees */
			printPathsRecur(node->left, path, pathLen);
			printPathsRecur(node->right, path, pathLen);
		}
	}
	void printArray(T ints[], int len)
	{
		int i;
		for (i = 0; i < len; i++)
		{
			cout << ints[i] << " ";
		}
		cout << endl;
	}
	void printPaths(Node* node)
	{
		T path[1000];
		printPathsRecur(node, path, 0);
	}
public:
	Tree() : root(nullptr) { }
	Tree(const Tree& another)
	{
		CtorCopyHelp(another.root);
	}
	~Tree()
	{
		DeleteTree(root);
	}

	bool IsEmpty() const { return root == nullptr; }

	void Add(const T& value)
	{
		this->Add(value, this->root);
	}

	void ShowFromLeft() const
	{
		// [L]eft[K]oren[R]ight
		ShowLKP(this->root);
	}
	void ShowFromRight() const
	{
		// [R]ight[K]oren[L]eft
		ShowPKL(this->root);
	}
	void ShowFromRoot()
	{
		printPaths(root);
	}


	bool Find(const T& value) { return Find(value, this->root); }

	void ShowMax() { ShowMax(root); }
	void ShowMin() { ShowMin(root); }

};