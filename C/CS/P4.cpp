#include <iostream>
using namespace std;
// *
// using pointer and recursion
int my_strlen(char *s)
{
    static int count = 0;
    if (*s == '\0')
    {
        return count;
    }
    ++count;
    return my_strlen(++s);
}
int main()
{
    char s[] = "IU is a girl!";
    printf("(%s) len = %d\n", s, my_strlen(s));
    return 0;
}