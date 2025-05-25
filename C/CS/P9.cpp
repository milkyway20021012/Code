#include <iostream>
using namespace std;

class Decoder
{
public:
    Decoder(string s) : str(s) {}
    string get_decode()
    {
        string ret;
        string now_alphbet;
        int count = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            count = 0;
            if (str[i] >= '1' && str[i] <= '9')
            {
                count = str[i] - '0';
                for (int j = 0; j < count; ++j)
                {
                    ret += now_alphbet; // 將now_alphbet（其實應該要說是當前字串）插入到結果的後面
                }
                now_alphbet = "";
            }
            else
            {
                now_alphbet += str[i];
            }
        }
        return ret;
    }

private:
    string str;
};

int main()
{
    Decoder d("A3BB2CCC2");
    cout << d.get_decode();

    return 0;
}