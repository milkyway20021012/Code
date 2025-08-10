#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 前向声明 BTNode 结构体
typedef struct BTree_Node BTNode;
typedef BTNode *QDataType;
// 队列结点结构
typedef struct QueueNode {
  QDataType val;
  struct QueueNode *next;
} QNode;
// 队列结构
typedef struct Queue {
  QNode *phead;
  QNode *ptail;
  int size;
} Queue;
// 初始化队列
void QueueInit(Queue *pq);
// 销毁队列
void QueueDestroy(Queue *pq);
// ⼊队列，队尾
void QueuePush(Queue *pq, QDataType x);
// 出队列，队头
void QueuePop(Queue *pq);
// 取队头数据
QDataType QueueFront(Queue *pq);
// 取队尾数据
QDataType QueueBack(Queue *pq);
// 队列判空
bool QueueEmpty(Queue *pq);
// 队列有效元素个数
int QueueSize(Queue *pq);