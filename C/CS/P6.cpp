#include <iostream>
using namespace std;
// *
int main()
{
    int line = 1;
    FILE *fp = fopen("P6.cpp", "r");
    char buf[256];
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        if (strstr(buf, "int main()"))
        {
            printf("%02d %s", line, buf);
            break;
        }
        ++line;
    }
    return 0;
}