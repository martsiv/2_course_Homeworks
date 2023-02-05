#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
	Graph<long> graph;

	graph.Add(6, { });
	graph.Add(4, { 6 });
	graph.Add(2, { 6, 4 });
	graph.Add(7, { 6, 2 });
	graph.Add(9, { 4 });
	graph.Add(0, { 2 });

	graph.Show();
	cout << "Node2\n";
	Graph<long> graph2(graph);
	graph.~Graph();
	graph2.Show();
	cout << "After deleted (9 , 2)\n9 will be deleted, because she has 1 relative. 2 will not be deleted, because she has several relatives\n";
	graph2.Delete(9);
	graph2.Delete(2);
	graph2.Show();
	cout << "\nChess tournament\n";
	Graph<string> graph3;
	string Vasil = "Vasil";
	string Maxim = "Maxim";
	string Semen = "Semen";
	string Anton = "Anton";
	string Ivan = "Ivan";
	string Denis = "Denis";
	string Evgen = "Evgen";
	graph3.Add(Vasil, {});							//played 6 games
	graph3.Add(Maxim, { Vasil });					//played 5 games
	graph3.Add(Semen, { Vasil, Maxim, Anton });		//played 3 games
	graph3.Add(Anton, { Vasil, Maxim, Semen });		//played 3 games
	graph3.Add(Ivan, { Vasil, Maxim });				//played 2 games
	graph3.Add(Denis, { Vasil, Maxim });			//played 2 games
	graph3.Add(Evgen, { Vasil });					//played 1 games
	graph3.Show();
	cout << "\nAnton:\n";
	graph3.Find(Anton);
}