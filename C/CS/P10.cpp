#include <iostream>
#include <string>
using namespace std;
class Bin2Decimal
{
public:
    Bin2Decimal(string str) : _str(str)
    {
    }
    int to_decimal()
    {
        return translate(_str);
    }
    int to_decimal(string str)
    {
        return translate(str);
    }

private:
    string _str;
    int translate(const string &str)
    {
        int len = str.size();
        int num = stoi(str);
        int ret = 0;
        int times = 1;
        for (int i = 1; i <= len; ++i)
        {
            ret += (num % 10) * times;
            times *= 2;
            num /= 10;
        }
        return ret;
    }
};
int main()
{
    Bin2Decimal d("1000");
    cout << d.to_decimal() << endl;
    cout << d.to_decimal("1010") << endl;
    return 0;
}