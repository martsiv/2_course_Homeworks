#pragma once
#include <iostream>
#include "Note.h"
#include "LinkedList.h"
using namespace std;

class NotesByTitle
{
	string title;
	LinkedList<Note> notes;
public:
	NotesByTitle(string title) : title(title) {}
	void Print() const { notes.Show(); }
	operator std::string() { return title; }
	void AddNote(string date, string content)
	{
		Note tmp(title, date, content);
		notes.AddTail(tmp);
	}
	void ChangeNote(string newContent)
	{
		try
		{
			notes.GoThroughAndReturn().SetContent(newContent);
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
	friend ostream& operator<< (ostream& out, const NotesByTitle& notesByTitle);
	friend bool operator< (const NotesByTitle& NotesByTitle1, const NotesByTitle& NotesByTitle2) { return NotesByTitle1.title < NotesByTitle2.title; }
	friend bool operator<= (const NotesByTitle& NotesByTitle1, const NotesByTitle& NotesByTitle2) { return NotesByTitle1.title <= NotesByTitle2.title; }
	friend bool operator> (const NotesByTitle& NotesByTitle1, const NotesByTitle& NotesByTitle2) { return NotesByTitle1.title > NotesByTitle2.title; }
	friend bool operator>= (const NotesByTitle& NotesByTitle1, const NotesByTitle& NotesByTitle2) { return NotesByTitle1.title >= NotesByTitle2.title; }
	friend bool operator== (const NotesByTitle& NotesByTitle1, const NotesByTitle& NotesByTitle2) { return NotesByTitle1.title == NotesByTitle2.title; }
	friend bool operator!= (const NotesByTitle& NotesByTitle1, const NotesByTitle& NotesByTitle2) { return NotesByTitle1.title != NotesByTitle2.title; }
};
ostream& operator<< (ostream& out, const NotesByTitle& notesByTitle)
{
	out << notesByTitle.title << ":\n";
	notesByTitle.notes.Show();
	return out;
};
