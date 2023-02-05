#pragma once
#include <iostream>
#include "NotesByTitle.h"
#include "Tree.h"
using namespace std;

class NoteBook
{
	Tree<NotesByTitle> notebook;
public:
	void AddNote(string title, string date, string content)
	{
		if (notebook.IsEmpty() || !notebook.Find(NotesByTitle(title)))
			notebook.Add(NotesByTitle(title));
		notebook.Find(NotesByTitle(title))->AddNote(date, content);
	}
	void PrintAll() const { notebook.ShowFromLeft(); }
	void PrintByTitle(string title)
	{
		NotesByTitle* tmp = notebook.Find(title);
		if (tmp)
			cout << *tmp << endl;
	}
	void ChangeNote(string title, string newContent)
	{
		NotesByTitle* tmp = notebook.Find(title);
		if (tmp)
			tmp->ChangeNote(newContent);
		else
			cout << "No notes found with this title\n";
	}
};
