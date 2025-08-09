#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// 单链表
// typedef int SLDataType;
// typedef struct SListNode {
//   struct SListNode *_next;
//   SLDataType _data;
// } SL;
// // 打印
// void SLPrint(SL *phead);
// SL *BuyNode(SLDataType x);
// // 尾插
// void SLPush_Back(SL **pphead, SLDataType x);
// // 尾删
// void SLPop_Back(
//     SL **pphead); // 这里传入的耳二级指针只有在删除第一个节点才有影响
// // 头插
// void SLPush_Front(SL **pphead, SLDataType x);
// // 头删
// void SLPop_Front(SL **pphead);
// // 查找
// SL *SL_Find(SL *pphead, SLDataType x);
// // 在指定位置之前插⼊数据
// void SLInsert(SL **pphead, SL *pos, SLDataType x);
// // 删除pos结点
// void SLErase(SL **pphead, SL *pos);
// // 在指定位置之后插⼊数据
// void SLInsertAfter(SL *pos, SLDataType x);
// // 删除pos之后的结点
// void SLEraseAfter(SL *pos);
// // 销毁链表
// void SListDestroy(SL **pphead);

// 双链表

typedef int SLDatatype;
typedef struct SListNode {
  struct SListNode *_prev;
  struct SListNode *_next;
  SLDatatype _data;
} SL;

// 初始化
SL *LTInit();
// 创建节点
SL *BuyNode(SLDatatype x);
void LTDestroy(SL *phead);
void LTPrint(SL *phead);
bool LTEmpty(SL *phead);
void LTPushBack(SL *phead, SLDatatype x);
void LTPopBack(SL *phead);
void LTPushFront(SL *phead, SLDatatype x);
void LTPopFront(SL *phead);
// 在pos位置之后插⼊数据
void LTInsert(SL *pos, SLDatatype x);
void LTErase(SL *pos);
SL *LTFind(SL *phead, SLDatatype x);
