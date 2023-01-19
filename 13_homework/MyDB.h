#pragma once
#include <iostream>
#include <string>
#include <functional>
#include "Class_User.h"
#include "Func.h"
#include "IncorrectName.h"
using namespace std;

class MyDB
{
	int size;
	User** user;
public:
	MyDB() : size(0), user(nullptr) {}
	~MyDB();
	void add();
	void remove(int index);
	User& find(string name);
	void sort(std::function<bool(string, string)> fcn);
	void Show(int index) const { user[index]->Show(); }
	int GetSize() const { return size; }
};