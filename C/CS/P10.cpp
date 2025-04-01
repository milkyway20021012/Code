#include <iostream>
#include <string>
using namespace std;

class Bin2Decimal
{
public:
    Bin2Decimal(string str) : Bin(str) {}

    // 因爲這題老師給的輸出結果有兩種模式，所以我採用函數重載
    string to_decimal()
    {
        string ret; // 用來返回輸出（但不確定是否一定要）
        ret += Bin;
        ret += " -> ";
        int num = stoi(Bin);
        int i = 1;
        int Decimal = 0; // 用來計算得到的結果
        while (num)
        {
            int last_num = num % 10;
            Decimal += (last_num * i);
            i *= 2;
            num /= 10;
        }
        string ret_to_string = to_string(Decimal);
        ret += ret_to_string;
        return ret;
    }
    string to_decimal(string str)
    {
        Bin = str;
        string ret;
        ret += Bin;
        ret += " -> ";
        int num = stoi(Bin);
        int i = 1;
        int Decimal = 0;
        while (num)
        {

            int last_num = num % 10;
            Decimal += (last_num * i);
            i *= 2;
            num /= 10;
        }
        string ret_to_string = to_string(Decimal);
        ret += ret_to_string;
        return ret;
    }

private:
    string Bin;
};
int main()
{
    Bin2Decimal d("1000");
    cout << d.to_decimal() << endl;
    cout << d.to_decimal("1111") << endl;
    return 0;
}