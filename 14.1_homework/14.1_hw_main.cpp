#include <iostream>
#include <string>
#include "Stack.h"

bool isCloset(char c1, char c2)
{
	switch (c1)
	{
	case '(': return c2 == ')';
	case '{': return c2 == '}';
	case '[': return c2 == ']';
	default: return false;
	}
}
int main()
{
	Stack<char> stack(20);
	string str{ "{(2{3(44)2}34)}" };
	int indexLastOpeningBracket = -1;
	try
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			{
				stack.Push(str[i]);
				indexLastOpeningBracket = i;
			}
			else if ((str[i] == ')' || str[i] == '}' || str[i] == ']'))
			{
				if (isCloset((char)stack.Peek(), str[i]))
					stack.Pop();
				else
				{
					throw exception(("Error in index " + std::to_string(i)).data());
				}
			}
		}
		if (!stack.IsEmpty())
			throw exception(("Error in index " + std::to_string(indexLastOpeningBracket)).data());
	}
	catch (const std::exception& ex)
	{
		cout << "Exception: " << ex.what();
	}

}