#include <iostream>
#include <functional>
#include <exception>
#include <string>
#include <climits>
using namespace std;

int ConvertStringToInt(string& str)
{
	int result = 0;
	int size = str.size();
	if (!size)
		throw exception("Size of string is 0");
	for (int i = size - 1, j = 1; 0 <= i; --i)
	{
		if (!i && (char(str[i]) == '-'))
			result *= -1;
		else if (!i && (char(str[i]) == '+'))
			continue;
		else if (!isdigit(char(str[i])))
			throw exception("Is not a digit");
		else
		{
			if (INT_MAX < (long long(result) + (long long(char(str[i])) - 48) * j))
				throw exception("Overflow");
			result += (int(char(str[i])) - 48) * j;
			j *= 10;
		}
	}
	return result;
}

int main()
{
	string test = "-1234567890";
	int result;
	try
	{
		result = ConvertStringToInt(test);
		cout << "Result: " << result;
	}
	catch (const exception& ex)
	{
		cout << "Message: " << ex.what() << endl;
	}
}