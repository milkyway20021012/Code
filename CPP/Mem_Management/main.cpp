#include <iostream>
using namespace std;

// int main()
// {
//     // C
//     int *p1 = (int *)malloc(sizeof(int) * 10);
//     free(p1);
//     // Cpp
//     int *p2 = new int[10]; // 开十个int 类型的空间
//     delete[] p2;
//     int *p3 = new int(10); // 开一个整型，并初始化
//     delete p3;
//     return 0;
// }

// struct ListNode
// {
//     int _val;
//     struct ListNode* _next;
//     ListNode(int x)
//         :_val(x)
//         ,_next(NULL)
//     {}
// };
// struct ListNode* BuyListNode(int x)
// {
//     // 单纯开空间
//     struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//     // 检查
//     newnode->_next = NULL;
//     newnode->_val = x;
//     return newnode;
// }
// int main()
// {
//     struct ListNode* n1 = BuyListNode(1);
//     struct ListNode* n2 = BuyListNode(2);
//     struct ListNode* n3 = BuyListNode(3);
//     // 开空间+调用构造函数初始化
//     ListNode* nn1 = new ListNode(1);
//     ListNode* nn2 = new ListNode(2);
//     ListNode* nn3 = new ListNode(3);
//     return 0;
// }





