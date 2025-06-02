#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Decoder
{

public:
    Decoder(string str) : _str(str)
    {
    }
    vector<string> get_decode()
    {
        vector<string> ret;
        int count = 0;
        string now_str = "";
        for (size_t i = 0; i < _str.size(); ++i)
        {
            if (isalpha(_str[i]))
            {
                now_str += _str[i];
            }
            else if (isdigit(_str[i]))
            {
                count = _str[i] - '0';
                for (int i = 1; i <= count; ++i)
                {
                    ret.push_back(now_str);
                }
                now_str = "";
            }
        }
        return ret;
    }

private:
    string _str;
};
ostream &operator<<(ostream &os, const vector<string> &vec)
{
    for (const auto &s : vec)
    {
        os << s;
    }
    return os;
}
int main()
{
    Decoder d("A3BB2CCC3");
    cout << d.get_decode();

    return 0;
}