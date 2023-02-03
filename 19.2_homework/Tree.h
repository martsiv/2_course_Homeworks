#pragma once
#include <iostream>
#include <functional>

using namespace std;

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
	void Add(const T& value, Node*& root);
	void ShowLKP(Node* root) const;
	void ShowPKL(Node* root) const;
	void ShowByRange(const T& leftT, const T& rightT, Node* root) const;
	T* Find(const T& value, Node* root);
	const T* Find(const T& value, Node* root) const;
	void ShowMax(const Node* root);
	void ShowMin(const Node* root);
	void DeleteTree(Node*& root);
	void CtorCopyHelp(const Node* another);
	void printPathsRecur(Node* node, T path[], int pathLen);
	void printArray(T ints[], int len);
	void printPaths(Node* node);
public:
	Tree() : root(nullptr) { }
	Tree(const Tree& another) {	CtorCopyHelp(another.root);	}
	~Tree()	{ DeleteTree(root);	}
	bool IsEmpty() const { return root == nullptr; }
	void Add(const T& value) { this->Add(value, this->root); }
	void ShowFromLeft() const {	ShowLKP(this->root); }
	void ShowFromRight() const { ShowPKL(this->root); }
	void ShowByRange(const T& leftT, const T& rightT) const { ShowByRange(leftT, rightT, root); }
	void ShowFromRoot() { printPaths(root);	}
	T* Find(const T& value) { return Find(value, this->root); }
	const T* Find(const T& value) const { return Find(value, this->root); }
	void ShowMax() { ShowMax(root); }
	void ShowMin() { ShowMin(root); }
};

template <typename T>
void Tree<T>::Add(const T& value, Node*& root)
{
	if (root == nullptr)
		root = new Node(value);
	else if (value > root->data)
		Add(value, root->right);
	else if (value < root->data)
		Add(value, root->left);
}

template <typename T>
void Tree<T>::ShowLKP(Node* root) const
{
	if (root == nullptr) return;

	//cout << " ( ";
	ShowLKP(root->left);
	cout << root->data << " ";
	ShowLKP(root->right);
	//cout << " ) ";
}

template <typename T>
void Tree<T>::ShowPKL(Node* root) const
{
	if (root == nullptr) return;

	//cout << " ( ";
	ShowPKL(root->right);
	cout << root->data << " ";
	ShowPKL(root->left);
	//cout << " ) ";
}

template<typename T>
inline void Tree<T>::ShowByRange(const T& leftT, const T& rightT, Node* root) const
{
	if (root == nullptr) return;

	ShowByRange(leftT, rightT, root->left);
	if ((leftT <= root->data) && (root->data <= rightT))
		cout << root->data << " ";
	ShowByRange(leftT, rightT, root->right);
}

template <typename T>
T* Tree<T>::Find(const T& value, Node* root)
{
	if (!root)
		return nullptr;
	if (value == root->data)
		return &root->data;
	if (value < root->data)
		return Find(value, root->left);
	if (root->data < value)
		return Find(value, root->right);
}

template <typename T>
const T* Tree<T>::Find(const T& value, Node* root) const
{
	if (!root)
		return nullptr;
	if (value == root->data)
		return &root->data;
	if (value < root->data)
		return Find(value, root->left);
	if (root->data < value)
		return Find(value, root->right);
}

template <typename T>
void Tree<T>::ShowMax(const Node* root)
{
	if (!root)
		return;
	if (!root->right)
		cout << root->data;
	else
		ShowMax(root->right);
}

template <typename T>
void Tree<T>::ShowMin(const Node* root)
{
	if (!root)
		return;
	if (!root->left)
		cout << root->data;
	else
		ShowMin(root->left);
}

template <typename T>
void Tree<T>::DeleteTree(Node*& root)
{
	if (root == nullptr) return;
	DeleteTree(root->left);
	DeleteTree(root->right);
	delete root;
}

template <typename T>
void Tree<T>::CtorCopyHelp(const Node* another)
{
	if (another == nullptr) return;
	Add(another->data);
	CtorCopyHelp(another->left);
	CtorCopyHelp(another->right);
}

template <typename T>
void Tree<T>::printPathsRecur(Node* node, T path[], int pathLen)
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

template <typename T>
void Tree<T>::printArray(T ints[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		cout << ints[i] << " ";
	}
	cout << endl;
}

template <typename T>
void Tree<T>::printPaths(Node* node)
{
	T path[1000];
	printPathsRecur(node, path, 0);
}