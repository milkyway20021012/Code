#include <iostream>
using namespace std;

// ***
class Decoder
{
public:
    Decoder(string s) : str(s) {}

    string str;
};

int main()
{
    Decoder d("A3BB2CCC2");
    // cout << d.get_decode();

    return 0;
}