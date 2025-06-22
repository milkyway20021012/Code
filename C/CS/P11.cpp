#include <iostream>
using namespace std;

// 單for 9*0

int main()
{
    for (int i = 1, j = 1; i <= 9;)
    {
        printf("%d*%d = %2d\t", i, j, i * j++);
        (j == 9) ? (i++, j = 1, printf("\n")) : i;
    }
    return 0;
}