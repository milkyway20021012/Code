#include "../include/slist.h"
#include <assert.h>
#include <string.h>
// 不带头单向循环链表
// 打印
// void SLPrint(SL *phead) {
//   SL *cur = phead;
//   while (cur) {
//     printf("%d->", cur->_data);
//     cur = cur->_next;
//   }
//   printf("NULL");
//   printf("\n");
// }
// SL *BuyNode(SLDataType x) {
//   SL *newnode = (SL *)malloc(sizeof(SL));
//   if (newnode == NULL) {
//     perror("malloc fail:");
//     return NULL;
//   }
//   newnode->_next = NULL;
//   newnode->_data = x;
//   return newnode;
// }
// // 尾插
// void SLPush_Back(SL **pphead, SLDataType x) {
//   assert(pphead);
//   // 如果插入的是第一个位置
//   SL *newnode = BuyNode(x);
//   if (*pphead == NULL) {
//     *pphead = newnode;
//     return;
//   }
//   // 找尾
//   SL *cur = *pphead;
//   while (cur->_next != NULL) {
//     cur = cur->_next;
//   }
//   cur->_next = newnode;
// }
// // 尾删
// void SLPop_Back(SL **pphead) {
//   // 尾删必须要确定传入的第一个节点不为空
//   assert(pphead && *pphead);
//   SL *prev = NULL;
//   SL *cur = *pphead;
//   if ((*pphead)->_next != NULL) {
//     while (cur->_next != NULL) {
//       prev = cur;
//       cur = cur->_next;
//     }
//     // 释放节点
//     free(cur);
//     cur = NULL;
//     prev->_next = NULL;
//     return;
//   }
//   free(*pphead);
//   (*pphead) = NULL;
// }
// // 头插
// void SLPush_Front(SL **pphead, SLDataType x) {
//   // 如果插入的是第一个节点
//   assert(pphead);
//   SL *newnode = BuyNode(x);
//   SL *phead = *pphead;
//   newnode->_next = phead;
//   *pphead = newnode;
// }
// // 头删
// void SLPop_Front(SL **pphead) {
//   assert(pphead && *pphead);
//   if ((*pphead) != NULL) {
//     SL *cur = *pphead;            // 记录*pphead的节点
//     (*pphead) = (*pphead)->_next; // 让*pphead指向它的_next
//     free(cur);
//     cur = NULL;
//   }
// }
// // 查找
// SL *SL_Find(SL *pphead, SLDataType x) {
//   assert(pphead);
//   SL *cur = pphead;
//   while (cur) {
//     if (cur->_data != x) {
//       cur = cur->_next;
//     } else {
//       printf("%d存在于链表中\n", x);
//       return cur;
//     }
//   }
//   return NULL;
// }
// // 在pos位置前插入
// void SLInsert(SL **pphead, SL *pos, SLDataType x) {
//   assert(pphead && pos);
//   if (*pphead == pos) {
//     SLPush_Front(pphead, x);
//     return;
//   }
//   SL *prev = *pphead;
//   while (prev->_next != pos) {
//     prev = prev->_next;
//   }
//   SL *newnode = BuyNode(x);
//   prev->_next = newnode;
//   newnode->_next = pos;
// }
// // 删除pos结点
// void SLErase(SL **pphead, SL *pos) {
//   assert(pphead && pos);
//   if (*pphead == pos) {
//     SLPop_Back(pphead);
//     return;
//   }
//   SL *prev = *pphead;
//   while (prev->_next != pos) {
//     prev = prev->_next;
//   }
//   prev->_next = pos->_next;
//   free(pos);
//   pos = NULL;
// }
// // 在指定位置之后插⼊数据
// void SLInsertAfter(SL *pos, SLDataType x) {
//   assert(pos);
//   SL *newnode = BuyNode(x);
//   newnode->_next = pos->_next;
//   pos->_next = newnode;
// }
// // 删除pos之后的结点
// void SLEraseAfter(SL *pos) {
//   assert(pos && pos->_next);
//   SL *del = pos->_next;
//   pos->_next = del->_next;
//   free(del);
//   del = NULL;
// }
// // 销毁链表
// void SListDestroy(SL **pphead) {
//   assert(*pphead);
//   while (*pphead != NULL) {
//     SLPop_Front(pphead);
//   }
// }

// 带头双向循环链表

// 初始化
SL *LTInit() {
  SL *head_node = (SL *)malloc(sizeof(SL));
  head_node->_next = head_node;
  head_node->_prev = head_node;
  head_node->_data = 0;
  return head_node;
}
// 创建节点
SL *BuyNode(SLDatatype x) {
  SL *newnode = (SL *)malloc(sizeof(SL));
  newnode->_data = x;
  newnode->_prev = newnode;
  newnode->_next = newnode;
  return newnode;
}
// 打印
void LTPrint(SL *phead) {
  printf("Head_Node->");
  SL *cur = phead->_next; // 哨兵位头节点不访问
  while (cur != phead) {
    printf("%d->", cur->_data);
    cur = cur->_next;
  }
  printf("Head_Node\n");
}
// 销毁节点
void LTDestroy(SL *phead) {
  SL *del = phead->_next;
  while (del != phead) {
    SL *next = del->_next;
    free(del);
    del = next;
  }
  phead->_next = phead;
  phead->_prev = phead;
}
// 判断是否为空
bool LTEmpty(SL *phead) {
  if (phead->_next == phead) {
    return true;
  }
  return false;
}
// 尾插
void LTPushBack(SL *phead, SLDatatype x) {
  SL *newnode = BuyNode(x);
  // 如果目前只有哨兵位节点
  if (LTEmpty(phead)) {
    phead->_next = newnode;
    phead->_prev = newnode;
    newnode->_prev = phead;
    newnode->_next = phead;
    return;
  }
  // 否则开始找尾
  SL *cur = phead->_next;
  while (cur->_next != phead) {
    cur = cur->_next;
  }
  cur->_next = newnode;
  newnode->_prev = cur;
  newnode->_next = phead;
  phead->_prev = newnode;
}
// 尾删
void LTPopBack(SL *phead) {
  assert(phead->_next != phead);
  SL *cur = phead->_next;
  while (cur->_next != phead) {
    cur = cur->_next;
  }
  SL *prev = cur->_prev;
  free(cur);
  cur = NULL;
  prev->_next = phead;
  phead->_prev = prev;
}
// 头插
void LTPushFront(SL *phead, SLDatatype x) {
  SL *newnode = BuyNode(x);
  if (phead->_next == phead) {
    LTPushBack(phead, x);
    return;
  }
  SL *first = phead->_next;
  phead->_next = newnode;
  newnode->_prev = phead;
  newnode->_next = first;
  first->_prev = newnode;
}
// 头删
void LTPopFront(SL *phead) {
  assert(phead->_next != phead);
  SL *del = phead->_next;
  SL *second = del->_next;
  free(del);
  del = NULL;
  phead->_next = second;
  second->_prev = phead;
}
// 在pos位置之后插⼊数据
void LTInsert(SL *pos, SLDatatype x) {
  SL *next = pos->_next;
  SL *newnode = BuyNode(x);
  pos->_next = newnode;
  newnode->_prev = pos;
  newnode->_next = next;
  next->_prev = newnode;
}
// 删除pos后位置的数据
void LTErase(SL *pos) {
  assert(pos->_next != pos);
  SL *next = pos->_next->_next;
  SL *del = pos->_next;
  free(del);
  del = NULL;
  pos->_next = next;
  next->_prev = pos;
}
SL *LTFind(SL *phead, SLDatatype x) {
  SL *cur = phead->_next;
  while (cur != phead) {
    if (cur->_data == x) {
      printf("%d Exist!\n", x);
      return cur;
    }
    cur = cur->_next;
  }
  printf("%d Not exist!\n", x);
  return NULL;
}