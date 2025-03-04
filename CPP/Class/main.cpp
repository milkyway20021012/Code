#include <iostream>
using namespace std;

// 构造函数和析构函数
class Stack
{
public:
    // 构造函数（自动调用）
    Stack()
    {
        cout << "Stack() 构造函数调用" << endl;
        _a = (int*)malloc(sizeof(int)*4);
        if(_a == nullptr){
            cout << "malloc fail" << endl;
            return;
        }
        _capacity = 4;
        _size = 0;
    }

    // 成员变量
private:
    int *_a;
    int _capacity;
    int _size;
};


int main(){
    Stack st;


    return 0;
}