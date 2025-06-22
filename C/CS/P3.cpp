#include <iostream>
#include <string>
using namespace std;
class my_string
{
};

class ReadClass
{
public:
    void showClass()
    {
        FILE *fp = fopen("/Users/milkyway1012/Desktop/Code/C/CS/P3.cpp", "r");
        char buf[256];
        int count = 0;
        while (fgets(buf, sizeof(buf), fp) != NULL)
        {
            if (strstr(buf, "class") == buf)
            {
                count++;
            }
        }
        cout << count << " class in main.cpp" << endl;
        rewind(fp);
        while (fgets(buf, sizeof(buf), fp) != NULL)
        {
            if (strstr(buf, "class") == buf)
            {
                cout << buf;
            }
        }
        fclose(fp);
        fp = nullptr;
    }
};
int main()
{
    ReadClass rfile;
    rfile.showClass();
    return 0;
}