// #include <iostream>
// using namespace std;
// class A
// {
// public:
//     A(int a)
//         : _a(a)
//     {
//     }
// private:
//     int _a;
// };
// class B
// {
// public:
//     // 初始化列表：对象的成员定义的地方
//     B(int a, int &ref)
//         : _aobj(a), _ref(ref), _n(10)
//     {
//     }
// private:
//     A _aobj; // 没有默认构造函数
//     /*
//     默认构造函数
//     1. 全缺省构造函数
//     2. 无参构造函数
//     3. 编译器自动生成的构造函数
//     */
//     // 特征：必须在定义的时候初始化
//     int &_ref;    // 引用
//     const int _n; // const
//     // 这里的1是缺省值，是给初始化列表的
//     // int x = 1;
// };
// typedef int DataType;
// class Stack
// {
// public:
//     Stack(size_t capacity = 10)
//     {
//         cout << "Stack 构造函数调用 " << endl;
//         _array = (DataType *)malloc(capacity * sizeof(DataType));
//         if (nullptr == _array)
//         {
//             perror("malloc申请空间失败");
//             return;
//         }
//         _size = 0;
//         _capacity = capacity;
//     }
//     void Push(const DataType &data)
//     {
//         // CheckCapacity();
//         _array[_size] = data;
//         _size++;
//     }
//     ~Stack()
//     {
//         if (_array)
//         {
//             free(_array);
//             _array = nullptr;
//             _capacity = 0;
//             _size = 0;
//         }
//     }
// private:
//     DataType *_array;
//     size_t _size;
//     size_t _capacity;
// }
// class MyQueue
// {
// public:
//     MyQueue()
//     {
//         cout << "MyQueue() 构造函数调用" << endl;
//     }
//     MyQueue(int capacity)
//         : _pushst(capacity), _popst(capacity)
//     {
//         cout << "MyQueue(int capacity) 调用" << endl;
//     }
// private:
//     Stack _pushst;
//     Stack _popst;
// };
// int main()
// {
//     // 对象整体定义
//     int n = 10;
//     B bb1(10, n);
//     // B bb2(11, 2);
//     MyQueue q1;
//     MyQueue q2(100);
//     return 0;
// }

#include <iostream>
using namespace std;

// class A
//{
// public:
//	/*explicit A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}*/
//
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
// private:
//	int _a;
// };
//
// int main()
//{
//	A aa1(1);
//	A aa2 = 2; // 隐式类型转换，整形转换成自定义类型
//	// 2构造一个A的临时对象，临时对象再拷贝构造aa2 -->优化用2直接构造
//
//	// error C2440: “初始化”: 无法从“int”转换为“A &”
//	//A& aa3 = 2;
//	const A& aa3 = 2;
//
//
//	int i = 10;
//	double d = i;
//
//	return 0;
// }

// int _scount = 0;
//
// class A
//{
// public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	~A() { --_scount; }
//	/*static int GetACount() { return _scount; }*/
// private:
//	/*static int _scount;*/
// };
//
// A aa0;
//
// void Func()
//{
//	static A aa2;
//	cout << __LINE__ << ":" << _scount << endl;
//
//	// 全局变量的劣势：任何地方都可以随意改变
//	_scount++;
// }
//
// int main()
//{
//	cout <<__LINE__<<":"<< _scount << endl;  // 1
//	A aa1;
//
//	Func();  // 3
//	Func();  // 3
//
//	return 0;
// }

// class A
//{
// public:
//	A()
//	{
//		++_scount;
//	}
//
//	A(const A& t)
//	{
//		++_scount;
//	}
//
//	~A()
//	{
//		--_scount;
//	}
//
//
//	void Func1()
//	{
//		// 非静态能否调用静态：可以
//		GetACount();
//	}
//
//	void Func2()
//	{
//		++_a1;
//	}
//
//	// 没有this指针，指定类域和访问限定符就可以访问
//	static int GetACount()
//	{
//		// 静态能否调用非静态：不可以。非静态的成员函数调用需要this指针，我没有this
//		// Func2();
//
//		//_a1++;
//		return _scount;
//	}
// private:
//	// 成员变量 -- 属于每个一个类对象，存储对象里面
//	int _a1 = 1;
//	int _a2 = 2;
////public:
//	// 静态成员变量 -- 属于类，属于类的每个对象共享，存储在静态区
//	static int _scount;
//};
//
//// 全局位置，类外面定义
// int A::_scount = 0;
//
// A aa0;
//
// void Func()
//{
//	static A aa2;
//	cout << __LINE__ << ":" << aa2.GetACount() << endl;
//
//	// 全局变量的劣势：任何地方都可以随意改变
//	//_scount++;
// }
//
// int main()
//{
//	cout <<__LINE__<<":"<< A::GetACount() << endl;  // 1
//	A aa1;
//
//	Func();  // 3
//	Func();  // 3
//
//	return 0;
// }

// 设计一个类，在类外面只能在栈上创建对象
// 设计一个类，在类外面只能在堆上创建对象
class A
{
public:
    // 静态成员函数不会传入this指针
    static A GetStackObj()
    {
        A aa;
        return aa;
    }

    static A *GetHeapObj()
    {
        return new A;
    }

private:
    A()
    {
    }

private:
    int _a1 = 1;
    int _a2 = 2;
};

int main()
{
    // static A aa1;   //  静态区
    // A aa2;          //  栈
    // A* ptr = new A; //  堆
    A::GetStackObj();
    A::GetHeapObj();

    return 0;
}
