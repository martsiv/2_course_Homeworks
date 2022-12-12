// Група ПД221. Микола Марців. Завдання 1
#include <iostream>
#include <string>

using namespace std;

struct Coord
{
	int xCoord;
	int yCoord;
};
class Rectangle
{
	int width;
	int height;
	char charVis;
	Coord coord;
public:
	Rectangle()
	{
		width = 0;
		height = 0;
		charVis = '*';
		coord.xCoord = 0;
		coord.yCoord = 0;
	}
	Rectangle(int size)
	{
		width = (size < 0) ? 1 : size;
		height = (size < 0) ? 1 : size;
		
		charVis = '*';
		coord.xCoord = 0;
		coord.yCoord = 0;
	}
	Rectangle(int width, int height)
	{
		this->width = (width < 0) ? 1 : width;
		this->height = (height < 0) ? 1 : height;

		charVis = '*';
		coord.xCoord = 0;
		coord.yCoord = 0;
	}
	void showRectangle()
	{
		cout << "  ";
		for (int i = 0, b = coord.xCoord; i < width; i++, b++)
			cout << b << ' ';
		cout << endl;
		for (int i = 0, b = coord.yCoord + height - 1; i < height; i++, b--)
		{
			cout << b << ' ';
			for (int j = 0; j < width; j++)
				cout << charVis << ' ';
			cout << endl;
		}
		cout << endl;
	}
	void setNewSize(int newWidth, int newHeight)
	{
		width = (newWidth < 0) ? 1 : newWidth;
		height = (newHeight < 0) ? 1 : newHeight;
	}
	void setNewCoords(int moveX, int moveY)
	{
		coord.xCoord += moveX;
		coord.yCoord += moveY;
	}
};

int main()
{
	Rectangle rtg{5, 4};
	rtg.showRectangle();
	rtg.setNewSize(3, 7);
	rtg.showRectangle();
	rtg.setNewCoords(-4, 10);
	rtg.showRectangle();
}