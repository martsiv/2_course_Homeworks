#pragma once
#include <iostream>
using namespace std;
class Note
{
	string title;
	string date;
	string content;
public:
	Note(string title, string date, string content) : title(title), date(date), content(content) {}
	const string& GetTitle() { return title; }
	const string& GetDate() { return date; }
	const string& GetContent() { return content; }
	void SetContent(const string& newContent) { content = newContent; }
	friend ostream& operator<< (ostream& out, const Note& note)
	{
		out << note.content << endl;
		out << note.date << endl;
		return out;
	}
};