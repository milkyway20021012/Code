#include <iostream>
using namespace std;
// *
int *clone_array(int *np, int n)
{
    int *clone = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        clone[i] = np[i];
    }
    return clone;
}

void print_array(int *p, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d,", *(p + i));
    }
    free(p);
}
int main()
{
    int n = 5;
    int np[5] = {0, 1, 2, 3, 4};
    int *p = clone_array(np, n);
    print_array(p, n);
    return 0;
}