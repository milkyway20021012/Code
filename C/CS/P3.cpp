#include <iostream>
#include <string>
using namespace std;
// *
class myString
{
};

class ReadClass
{
public:
    void showClass()
    {
        FILE *fp = fopen("P3.cpp", "r");
        char buf[256];
        while (fgets(buf, sizeof(buf), fp) != NULL)
        {
            if (strstr(buf, "class") == buf)
            {
                ++count;
            }
        }
        cout << count << " class in main.cpp" << endl;
        rewind(fp);
        while (fgets(buf, sizeof(buf), fp) != NULL)
        {
            if (strstr(buf, "class ") == buf) // 這裡的buf 是 buf的起始位置
            {
                cout << buf;
            }
        }
        fclose(fp);
        fp = nullptr;
    }

private:
    static int count;
};
int ReadClass::count = 0;
int main()
{
    ReadClass rfile;
    rfile.showClass();
    return 0;
}