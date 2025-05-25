#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 定义结构体 ( 我们的队列以单链表方式实现 )

typedef struct BinaryTreeNode*  QDataType;


// 关注单个节点的数据存储（data）和 节点间的链接关系（next）
typedef struct QueueNode {
	struct QueueNode* next;
	QDataType data;

}QNode;

// 对队列整体进行管理
typedef struct Queue {
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);

QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);