#include <iostream>
#include "NoteBook.h"
using namespace std;

int main()
{
	string title1 = "Title1";
	string title2 = "Title2";
	string title3 = "Title3";
	NoteBook notebook;
	notebook.PrintAll();
	notebook.AddNote(title1, "03.02.2022", "Bla bla bla");
	notebook.AddNote(title3, "04.02.2022", "Bla bla bla");
	notebook.AddNote(title2, "05.02.2022", "Bla bla bla");
	notebook.AddNote(title2, "06.02.2022", "sdfgsdfgdsfg");
	notebook.AddNote(title2, "07.02.2022", "erguisehrkgj");
	notebook.PrintAll();
	cout << "Change note by title: " << title2 << endl;
	notebook.ChangeNote(title2, "Your new note");
	notebook.PrintByTitle(title2);
}