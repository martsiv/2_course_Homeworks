#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

int main()
{
    Tree<long> tree;

    tree.Add(8);
    tree.Add(10);
    tree.Add(3);
    tree.Add(1);
    tree.Add(6);
    tree.Add(14);
    tree.Add(4);
    tree.Add(7);
    tree.Add(13);

    tree.ShowFromLeft();
    cout << "\n----------------\n";
    tree.ShowFromRight();
    cout << "\n----------------\n";
    int val = 14;
    cout << "Find value " << val << " - " << tree.Find(val) << endl;
    cout << "\nShow Max value: ";
    tree.ShowMax();
    cout << "\nShow Min value: ";
    tree.ShowMin();
    cout << "\n----------------\n";
    Tree<long> tree2(tree);
    tree2.ShowFromLeft();
    cout << "\nShow from root\n";
    tree2.ShowFromRoot();
}