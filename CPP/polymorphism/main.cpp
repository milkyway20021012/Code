#include <iostream>
using namespace std;
// class Person
// {
// public:
//     virtual void Buyticket() final
//     {
//         cout << "全票" << endl;
//     }
// };

// class Student : public Person
// {
// public:
//     virtual void Buyticket()
//     {
//         cout << "七五折" << endl;
//     }
// };
// void func(Person & p){
//     p.Buyticket();
// }
// int main()
// {
//     Person p;
//     Student st;

//     func(p);
//     func(st);
//     return 0;
// }

// class Car
// {
// public:
//     virtual void Derive() = 0;
//     void func1() {}
//     void func1(int) {}
//     void func2() {}
// };

// class BMW : public Car
// {
// public:
//     virtual void Derive() override
//     {
//         cout << "BMW" << endl;
//     }
// };

// class Benz : public Car
// {
// public:
//     virtual void Derive() override
//     {
//         cout << "Benz" << endl;
//     }
//     void Print()
//     {
//         cout << this->func1(5) << endl;
//     }
// };

// int main()
// {
//     // Car car;
//     Car *pBenz = new Benz;
//     Car *pBMW = new BMW;
//     pBenz->Derive();
//     pBMW->Derive();
//     cout << pBenz->func1(5) << end;
//     l return 0;
// }

// class A
// {
// public:
//     virtual void test(int a) { 
//         cout << a; 
//         cout << "調用A::test(float a)" << endl;
//     }
// };
// class B : public A
// {
// public:
//     virtual void test(int b) { 
//         cout << b; 
//         cout << "調用B::test(int b)" << endl;
//     }
// };
// int main()
// {
//     A *a = new A;
//     B *b = new B;
//     a = b;
//     a->test(1);
// }

// class A
// {
// public:
//     virtual void f()
//     {
//         cout << "A::f()" << endl;
//     }
// };

// class B : public A
// {
// private:
//     virtual void f()
//     {
//         cout << "B::f()" << endl;
//     }
// };
// int main()
// {
//     A *pa = (A *)new B;
//     pa->f();
//     return 0;
// }


// class A
// {
// public:
//     A() : m_iVal(0) { test(); }
//     virtual void func() { std::cout << m_iVal << " "; }
//     void test() { func(); }

// public:
//     int m_iVal;
// };
// class B : public A
// {
// public:
//     B() { test(); }
//     virtual void func()
//     {
//         ++m_iVal;
//         std::cout << m_iVal <<" ";
//     }
// };

// int main(int argc, char *argv[])
// {
//     A *p = new B;
//     p->test();
//     return 0;
// }

// ------------------------------------------

class A{
    public:
    virtual void func1(){
        cout << "A -- func1" << endl;
    }
};


class B : public A{
    public:
    virtual void func1(){
        cout << "B -- func1" << endl;
    }
};



int main(){

    A* ptr = new B;

    ptr->func1();
    return 0;
}