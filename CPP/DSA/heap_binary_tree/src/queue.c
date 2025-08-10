#include "../include/queue.h"

// 初始化队列
void QueueInit(Queue *pq) {
  assert(pq);
  pq->phead = NULL;
  pq->ptail = NULL;
  pq->size = 0;
}
// 销毁队列
void QueueDestroy(Queue *pq) {
  assert(pq);
  QNode *cur = pq->phead;
  QNode *del = NULL;
  while (cur) {
    del = cur;
    cur = cur->next;
    free(del);
    del = NULL;
  }
  pq->phead = NULL;
  pq->ptail = NULL;
  pq->size = 0;
}
// ⼊队列，队尾
void QueuePush(Queue *pq, QDataType x) {
  assert(pq);
  QNode *newnode = (QNode *)malloc(sizeof(QNode));
  newnode->val = x;
  if (pq->phead == NULL) {
    pq->phead = newnode;
    pq->ptail = newnode;
    ++pq->size;
    pq->ptail->next = NULL;
    return;
  }
  pq->ptail->next = newnode;
  pq->ptail = pq->ptail->next;
  pq->ptail->next = NULL;
  ++pq->size;
}
// 出队列，队头
void QueuePop(Queue *pq) {
  assert(pq && pq->phead);
  QNode *del = pq->phead;
  pq->phead = pq->phead->next;
  free(del);
  del = NULL;
  pq->size--;
}
// 取队头数据
QDataType QueueFront(Queue *pq) {
  assert(pq && pq->phead);
  return pq->phead->val;
}
// 取队尾数据
QDataType QueueBack(Queue *pq) {
  assert(pq);
  return pq->ptail->val;
}
// 队列判空
bool QueueEmpty(Queue *pq) {
  assert(pq);
  return pq->size == 0;
}
// 队列有效元素个数
int QueueSize(Queue *pq) {
  assert(pq);
  return pq->size;
}