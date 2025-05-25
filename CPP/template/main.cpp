#include <iostream>
using namespace std;
template <typename T>
void Swap(T &x1, T &x2)
{
    T tmp = x1;
    x1 = x2;
    x2 = tmp;
}
int main()
{
    int a = 1, b = 2;
    double c = 20.1, d = 30.2;
    Swap(a, b);
    Swap(c, d);
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    return 0;
}