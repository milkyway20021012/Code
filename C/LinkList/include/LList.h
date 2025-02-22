#include <stdio.h>
#include <stdlib.h>
typedef char LListDataType;

// 定義結構
typedef struct LListNode{
    LListDataType data; //儲存輸入的字元
    int count; // 計算個數
    struct LListNode *next; //指向下一個節點
}LNode;

// Print

void Print(LNode *phead);

LNode* CreateNode(LListDataType ch);

void LListPushBack(LNode** phead, LListDataType ch);

