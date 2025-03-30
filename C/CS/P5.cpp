#include <iostream>
using namespace std;
// *
int main()
{
    FILE *fp = fopen("hello.txt", "w");
    fputs("hello, B1129055", fp);
    fclose(fp);
    fp = NULL;
    return 0;
}