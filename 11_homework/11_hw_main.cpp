#include <iostream>
#include <fstream>
#include <string>
#include <initializer_list>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Shape
{
private:
	string name;
public:
	Shape(string name) : name(name) {}
	virtual ~Shape() {};
	virtual void Print() const = 0;
	virtual void SaveShapes(string filename) const = 0;
	friend std::ostream& operator<<(std::ostream& out, const Shape& shape);
};

class Line : public Shape
{
private:
	Point start = { 0, 0 };
	Point end = { 0, 0 };
public:
	Line(string name, const Point& start, const Point& end) : Shape(name), start(start), end(end) {}
	void Print() const override;
	void SaveShapes(string filename) const override;
	friend std::ostream& operator<<(std::ostream& out, const Line& line);
};

class Rectangle : public Shape
{
private:
	Point start = { 0, 0 };
	int width = 0;
	int length = 0;
public:
	Rectangle(string name, const Point& start, int width, int length) : Shape(name), start(start), width(width), length(length) {}
	void Print() const override;
	void SaveShapes(string filename) const override;
	friend std::ostream& operator<<(std::ostream& out, const Rectangle& rectangle);
};

class Polyline : public Shape
{
private:
	int numOfPoints = 0;
	Point* points = nullptr;
public:
	Polyline(string name, initializer_list<Point> points);
	Polyline(const Polyline& polyline);
	void Print() const override;
	void AddPoint(const Point& point);
	~Polyline()
	{
		delete[] points;
		points = nullptr;
		numOfPoints = 0;
	}
	void SaveShapes(string filename) const override;
	friend std::ostream& operator<<(std::ostream& out, const Polyline& polyline);
};

int main()
{
	Line line("Line 1", { 2, 3 }, { 4, 5 });
	Rectangle rectangle("Rectangle 1", { 5, 5 }, 8, 6);
	Polyline polyline("Polyline 1", { {3, 4}, {4, 5}, {6, 8} });
	Line line2("Line 2", { 5, 6 }, { 11, 13 });
	int size = 4;
	Shape** shape = new Shape * [size] {&line, & rectangle, & polyline, & line2};
	for (int i = 0; i < size; i++)
	{
		shape[i]->Print();
		shape[i]->SaveShapes(to_string(i) + "shape.txt");// 
	}
}

std::ostream& operator<<(std::ostream& out, const Shape& shape)
{
	out << " ------------------- " << shape.name << " ------------------- \n";
	return out;
}

void Line::Print() const
{
	cout << *this;
}
void Line::SaveShapes(string filename) const
{
	ofstream fout(filename);
	fout << *this;
	fout.close();
}
std::ostream& operator<<(std::ostream& out, const Line& line)
{
	out << dynamic_cast<const Shape&> (line);
	out << "Start point\nx = " << line.start.x << "\ny = " << line.start.y << endl;
	out << "End point\nx = " << line.end.x << "\ny = " << line.end.y << endl;
	return out;
}

void Rectangle::Print() const
{
	cout << *this;
}
std::ostream& operator<<(std::ostream& out, const Rectangle& rectangle)
{
	out << dynamic_cast<const Shape&> (rectangle);
	out << "Start point\nx = " << rectangle.start.x << "\ny = " << rectangle.start.y << endl;
	out << "Width = " << rectangle.width << endl;
	out << "Length = " << rectangle.length << endl;
	return out;
}
void Rectangle::SaveShapes(string filename) const
{
	ofstream fout(filename);
	fout << *this;
	fout.close();
}
Polyline::Polyline(string name, initializer_list<Point> points) : Shape(name)
{
	numOfPoints = points.size();
	this->points = new Point[numOfPoints];
	int i = 0;
	for (const Point* ptr = points.begin(); ptr != points.end(); ptr++, i++)
	{
		this->points[i] = *ptr;
	}
}
Polyline::Polyline(const Polyline& polyline) : Shape(polyline)
{
	this->numOfPoints = polyline.numOfPoints;
	points = new Point[numOfPoints];
	for (int i = 0; i < numOfPoints; i++)
		this->points[i] = polyline.points[i];
}

void Polyline::Print() const
{
	cout << *this;
}
std::ostream& operator<<(std::ostream& out, const Polyline& polyline)
{
	out << dynamic_cast<const Shape&> (polyline);
	if (!polyline.points)
	{
		cout << "There are no points\n";
	}
	else
	{
		for (int i = 0; i < polyline.numOfPoints; i++)
			cout << i + 1 << " point.\t x = " << polyline.points[i].x << " y = " << polyline.points[i].y << endl;
		cout << endl;
	}
	return out;
}

void Polyline::AddPoint(const Point& point)
{
	++numOfPoints;
	if (!points)
	{
		points = new Point{ point };
	}
	else
	{
		Point* tmp = new Point[numOfPoints];
		for (int i = 0; i < numOfPoints - 1; i++)
			tmp[i] = points[i];
		tmp[numOfPoints - 1] = point;
		delete[] points;
		points = tmp;
	}
}
void Polyline::SaveShapes(string filename) const
{
	ofstream fout(filename);
	fout << *this;
	fout.close();
}
