#include <iostream>
using namespace std;
// *
int my_strlen(char *s)
{
    int count = 0;
    while (*s)
    {
        count++;
        s++;
    }
    return count;
}
int main()
{
    char s[] = "IU is a girl!";
    printf("(%s) len = %d\n", s, my_strlen(s));
    return 0;
}