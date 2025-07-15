#include "../include/BST.h"
using namespace std;
// int main()
// {
//     BST<int> bst;
//     int a[] = {8, 3, 1, 10, 6, 4, 7, 14, 13};
//     for (size_t i = 0; i < sizeof(a) / sizeof(int); ++i)
//     {
//         bst.insert(a[i]);
//     }

//     for (auto e : a)
//     {
//         if (bst.Find(e))
//         {
//             bst.erase(e);
//         }
//         bst.InOrder();
//     }
//     return 0;
// }

// int main()
// {
//     BST_K_V::BST<string, string> dict;
//     // BSTree<string, string> copy = dict;
//     dict.insert("left", "左边");
//     dict.insert("right", "右边");
//     dict.insert("insert", "插入");
//     dict.insert("string", "字符串");
//     string str;
//     while (cin >> str)
//     {
//         auto ret = dict.Find(str);
//         if (ret)
//         {
//             cout << str << "->" << ret->_value << endl;
//         }
//         else
//         {
//             cout << "无此单词，请重新输入" << endl;
//         }
//     }
//     return 0;
// }

int main()
{
    string arr[] = {"苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉"};
    BST_K_V::BST<string, int> countTree;
    for (const auto &str : arr)
    {
        // 先查找水果在不在搜索树中
        //  1. 不在， 水果第一次出现，则插入水果，
        //  2. 在， 则查找到的结点中水果对应的次数++
        // BSTreeNode<string, int>* ret = countTree.Find(str);
        auto ret = countTree.find(str);
        if (ret == NULL)
        {
            countTree.insert(str, 1);
        }
        else
        {
            ret->_val++;
        }
    }
    countTree.InOrder();
    return 0;
}

// int main()
// {
//     int a[] = {8, 3, 1, 10, 6, 4, 7, 14, 13};
//     BST<int> bst;
//     for (auto &e : a)
//     {
//         bst.insert(e);
//     }

//     for (auto &e : a)
//     {
//         bst.erase(e);
//         bst.InOrder();
//     }
   
//     return 0;
// }