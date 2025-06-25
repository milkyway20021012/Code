#include <iostream>
#include <list>
#include "../include/list.h"
using namespace std;
int main()
{
    // list<int> lt;
    // lt.push_back(1);
    // lt.push_back(2);
    // lt.push_back(3);
    // lt.push_back(4);
    // lt.push_back(5);
    // for (auto e : lt)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;

    // bit::test01();
    // bit::test02();
    // bit::test03();
    // bit::test04();
    // bit::test05();

    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = sizeof(ar) / sizeof(int);

    list<int> mylist(ar, ar + n);

    list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);

    reverse(mylist.begin(), pos);
    for (auto e : mylist)
    {
        cout << e << " ";
    }
    cout << endl;
    reverse(pos, mylist.end());
    for (auto e : mylist)
    {
        cout << e << " ";
    }
    cout << endl;
    list<int>::const_reverse_iterator crit = mylist.crbegin();

    while (crit != mylist.crend())

    {

        cout << *crit << " ";

        ++crit;
    }

    cout << endl;
    return 0;
}