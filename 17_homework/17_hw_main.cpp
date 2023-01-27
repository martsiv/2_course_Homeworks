#include <iostream>
#include "List.h"
#include "Point.h"

using namespace std;

int main()
{
    List<short> list;

    list.InsertItem(111, 0);
    list.Show();

    list.AddHead(99);
    list.AddHead(1);
    list.AddHead(17);
    list.AddHead(3);
    list.AddHead(8);
    list.Show();
    list.Reverse();
    list.Show();
    list.DeleteByIndex(3);
    list.Show();
    List<Point> list2;
    list2.AddHead({ 2, 3 });
    list2.AddTail({ 4, 8 });
    list2.AddHead({ 6, -3 });
    cout << "List2 Print = ";
    list2.Show();

    cout << "\nGet first Print:\n";
    list2.GetFirst().Print();

    Point tmp = list2.GetFirst();
    tmp++;
    cout << endl << tmp;
    --tmp;
    cout << endl << tmp;
    !tmp;
    cout << endl << tmp;

    Point tmp2 = list2.GetLast();
    cout << "\ntmp1 = " << tmp << "\ttmp2 = " << tmp2 << endl;
    cout << "tmp1 " << (tmp < tmp2 ? '<' : '>') << " tmp2\n";
}