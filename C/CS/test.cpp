#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3};
    int *p = arr;
    printf("%d",*++p);
    return 0;
}