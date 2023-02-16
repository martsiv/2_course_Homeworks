#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <iterator>
#include <algorithm>
#include <initializer_list>
using namespace std;
enum class SyzeType { M = 1, L, XL };
enum class ColorType { Black = 1, Cyan, Magenta, Yellow };

class Document
{
	string name;
	int pages;
	string format;
public:
	Document(string name, int pages, string format)
		: name(name), pages(pages), format(format) {}
	void ShowInfo() const
	{
		cout << "Document: " << name << endl;
		cout << "Pages: " << pages << endl;
		cout << "Format: " << format << endl;
	}
	int GetPages() const { return pages; }
	friend std::ostream& operator<< (std::ostream& out, const Document& document)
	{
		out << "Document: " << document.name << endl;
		out << "Pages: " << document.pages << endl;
		out << "Format: " << document.format << endl;
		return out;
	}
};
class Scanner
{
	string model;
	int dpi;
public:
	Scanner(string model, int dpi) : model(model), dpi(dpi) {}
	Document* Scan(Document& doc)
	{
		Document* tmp = new Document(doc);
		return tmp;
	}
	void ShowInfo() const
	{
		cout << model << " " << dpi << endl;
	}
};

class Cartridge
{
	float volume;		//current size
	float capacity;		//max size
	ColorType color;
	SyzeType size;
public:
	Cartridge(float volume, float capacity, ColorType color, SyzeType size)
		: volume(volume), capacity(capacity), color(color), size(size) {}
	bool IsEmpty() const { return volume == 0; }
	bool IsFull() const { return volume == capacity; }
	string GetSize() const
	{
		switch (size)
		{
		case SyzeType::M:
			return "M";
		case SyzeType::L:
			return "L";
		case SyzeType::XL:
			return "XL";
		default:
			break;
		}
	}
	string GetColor() const
	{
		switch (color)
		{
		case ColorType::Black:
			return "Black";
		case ColorType::Cyan:
			return "Cyan";
		case ColorType::Magenta:
			return "Magenta";
		case ColorType::Yellow:
			return "Yellow";
		default:
			break;
		}
	}
	void ShowInfo() const
	{
		cout << "Size type: " << GetSize() << endl;
		cout << "Paint: " << volume << "/" << capacity << endl;
		cout << "Color: " << GetColor() << endl;
	}
	void Print(int pages)
	{
		volume -= pages * 2;
	}
	void Fill()
	{
		volume = capacity;
	}
};


class Printer
{
	string model;
	vector<Cartridge*> cartridge;
	queue<Document*> Queue;
	Scanner scanner;

public:
	Printer(string model, string scannerModel, int dpi, initializer_list<Cartridge*> list)
		: scanner(scannerModel, dpi), model(model)
	{
		for (auto& element : list)
		{
			cartridge.push_back(element);
		}
	}
	void EnqueueDocument(Document* doc)
	{
		Queue.push(doc);
	}
	void FillTheInk()
	{
		for (auto i : cartridge)
			i->Fill();
	}
	
	void ClearQueue()
	{
		while (Queue.empty())
			Queue.pop();
	}
	void Print()
	{
		for (auto i : cartridge)
		{
			if (i->IsEmpty())
			{
				cout << "Out of ink\n";
				break;
			}
		}
		cout << "Printed:\n";
		Queue.front()->ShowInfo();
		for (auto i : cartridge)
		{
			i->Print(Queue.back()->GetPages());
		}
		Queue.pop();
	}
	Document* ScanDocument(Document& doc)
	{
		return scanner.Scan(doc);
	}
};

int main()
{
	Document* doc1 = new Document("Doc1", 13, "A4");
	Document* doc2 = new Document("Doc2", 17, "A4");
	Document* doc3 = new Document("Doc3", 7, "A4");
	Document* doc4 = new Document("Doc4", 9, "A4");
	Document* doc5 = new Document("Doc5", 2, "A4");
	Cartridge* cart1 = new Cartridge(250000, 250000, ColorType::Black, SyzeType::M);
	Cartridge* cart2 = new Cartridge(250000, 250000, ColorType::Cyan, SyzeType::M);
	Cartridge* cart3 = new Cartridge(250000, 250000, ColorType::Magenta, SyzeType::M);
	Cartridge* cart4 = new Cartridge(250000, 250000, ColorType::Yellow, SyzeType::M);
	Printer printer("HP", "HP", 1080, {cart1, cart2, cart3, cart4});
	printer.EnqueueDocument(doc1);
	printer.EnqueueDocument(doc2);
	printer.EnqueueDocument(doc3);
	printer.EnqueueDocument(doc4);
	printer.EnqueueDocument(doc5);
	printer.Print();
	printer.Print();
	printer.Print();
	Document* doc6 = printer.ScanDocument(*doc1);
	cout << endl << *doc6 << endl;
	delete doc1;
	delete doc2;
	delete doc3;
	delete doc4;
	delete doc5;
	delete doc6;
	delete cart1;
	delete cart2;
	delete cart3;
	delete cart4;
}