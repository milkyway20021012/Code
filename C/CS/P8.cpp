#include <iostream>
using namespace std;
// *
int rec_Fibonacci(int n)
{
    if (n == 0)
    {
        return 0; // 要記得寫結束條件
    }
    return n + rec_Fibonacci(n - 1);
}
int main()
{
    int n = 10;
    int sum = rec_Fibonacci(n);
    printf("Fibonacci(%d) = %d", n, sum);
    return 0;
}