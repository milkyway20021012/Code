#include <iostream>
using namespace std;

int reverse(int num)
{
    static int reversed = 0;
    if (num == 0)
    {
        return reversed;
    }
    reversed = (reversed * 10) + (num % 10);
    return reverse(num / 10);
}
int main()
{
    int num = 54321;
    cout << reverse(num) << endl;
    return 0;
}

