#include <iostream>
#include <string>
using namespace std;

// classPerson
//{
// Person(){};
// Person(stringN="Peter",stringA="马里亚纳海沟",stringPN="111",intAge=18):_Name(N),
//_Address(A),
//_Phone_Number(PN),
//_Age(Age){}
// protected:
// string_Name;//名字
// string_Address;//地址
// string_Phone_Number;//电话号码
// int_Age;//年龄
// };

////继承的语法
////class派生类名:继承方式基类名
////老师类
// classTeacher:publicPerson
//{
// public:
////这里可能有一些方法
////...
// protected:
// string_Title;//职称
// };
////学生类
// classStudent:publicPerson
//{
// public:
////这里可能有一些方法
////...
// protected:
// int_Student_id;//学号
// };

// 类模版的继承
// namespacebit
//{
// template<classT>
// classstack:publicstd::vector<T>
//{
// public:
// voidpush(constT&val)
//{
///*
// 基类是类模板时，需要指定一下类域
// 否则编译报错：errorC3861：“push_back”：找不到标识符
// 因为stack<int>实例化时，也实例化vector<int>了
// 但是模版是按需实例化，push_back等成员函数未实例化，所以找不到
//*/
// vector<T>::push_back(val);
////push_back(val);
//}
//};
//}
// intmain()
//{
// bit::stack<int>st;
// st.push(3);
// return0;
//}

// classPerson
//{
// public:
// voidfunc(inta){}
// };
// classStudent:publicPerson
//{
// public:
// voidfunc(){}
// };

// 继承的默认函数

// classPerson
//{
// public:
// Person(constchar*name="Peter"):_name(name)
//{
// cout<<"Person(constchar*name)调用"<<endl;
// }
// Person(constPerson&p)
//{
//_name=p._name;
// cout<<"Person拷贝构造调用"<<endl;
// }
// Person&operator=(constPerson&p)
//{
// cout<<"Personoperator=(constPerson&p)"<<endl;
// if(this!=&p)
//_name=p._name;
// cout<<"PersonOperator=ending"<<endl;
// return*this;
// }
//~Person()
//{
// cout<<"~Person()调用"<<endl;
// }
// protected:
// string_name;
// };
// classStudent:publicPerson
//{
// public:
// Student(constchar*name,intnum)
//: Person(name),
//_num(num)
//{
// cout<<"Student()"<<endl;
//}
// Student(constStudent&s)
//: Person(s),_num(s._num)
//{
// cout<<"Student(constStudent&s)"<<endl;
//}
// Student&operator=(Student&s)
//{
// cout<<"Student&operator=(constStudent&s)"<<endl;
// if(this!=&s)
//{
////构成隐藏，所以需要显示调用
// this->Person::operator=(s);
//_num=s._num;
// }
// cout<<"Studentoperator=ending"<<endl;
// return*this;
// }
// private:
// int_num;
// };
// intmain()
//{
// Students1("Jack",18);
// cout<<"------------------分隔线------------------"<<endl;
// Students2(s1);
// cout<<"------------------分隔线------------------"<<endl;
// Students3("Cindy",20);
// cout<<"------------------分隔线------------------"<<endl;
// s3=s1;
// cout<<"------------------分隔线------------------"<<endl;
// return0;
// }

// classStudent;
// classPerson
//{
// public:
// friendvoiddisplay(constPerson&p,constStudent&s);
// Person(constchar*name="Peter"):_name(name){}
// protected:
// string_name;
// };
// classStudent:publicPerson
//{
// public:
////friendvoiddisplay(constPerson&p,constStudent&s);
// Student(intnum=18):_num(num){}
// protected:
// int_num;
// };
// voiddisplay(constPerson&p,constStudent&s)
//{
// cout<<p._name<<endl;
// cout<<s._num<<endl;
// }
// intmain()
//{
// Personp;
// Students;
// display(p,s);
// return0;
// }

// class Person
// {
// public:
//     string _name;
//     static int _count;
// };
// int Person::_count = 0;
// class Student : public Person
// {
// protected:
//     int _stuNum;
// };
// int main()
// {
//     Person p;
//     Student s;
//     // 这里的运行结果可以看到非静态成员 _name的地址是不一样的
//     // 说明派生类继承下来了，父派生类对象各有一份
//     cout << &p._name << endl;
//     cout << &s._name << endl;
//     // 这里的运行结果可以看到静态成员_count的地址是一样的
//     // 说明派生类和基类共用同一份静态成员
//     cout << &p._count << endl;
//     cout << &s._count << endl;
//     // 公有的情况下，父派生类指定类域都可以访问静态成员
//     cout << Person::_count << endl;
// }

// class Person
// {
// public:
//     string _name; // 姓名
// };
// class Student : public Person
// {
// protected:
//     int _num; // 学号
// };

// class Teacher : public Person
// {
// protected:
//     int _id; // 职工编号
// };
// class Assistant : public Student, public Teacher
// {
// protected:
//     string _majorCourse; // 主修课程
// };
// int main()
// {
//     // 编译报错：error C2385: 对“ _name”的访问不明确
//     Assistant a;
//     // a._name = "peter";

//     // 需要显示指定访问哪个基类的成员可以解决二义性问题，但是数据冗余问题无法解决
//     a.Teacher::_name = "xxx";
//     a.Student::_name = "yyy";

//     return 0;
// }

class Person
{
public:
    string _name;
};
// 使用虚继承Person类
class Student : virtual public Person
{
protected:
    int _num; // 学号
};
// 使用虚继承Person类
class Teacher : virtual public Person
{
protected:
    int _id; // 职工编号
};
// 教授助理
class Assistant : public Student, public Teacher
{
protected:
    string _majorCourse; // 主修课程
};
int main()
{
    // 使用虚继承，可以解决数据冗余和二义性
    Assistant a;
    a._name = "peter";
    return 0;
}