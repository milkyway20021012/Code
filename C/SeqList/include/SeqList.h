#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 顺序表实现

// 结构体定义

typedef int SLDatatype;
typedef struct SList
{
    SLDatatype *a;
    int size;
    int capacity;
} SL;

// 对数据的管理 -- 增删查改

// 初始化顺序表

void SLInit(SL *ps);
// 顺序表的销毁
void SLDestroy(SL *ps);
// 打印
void SLPrint(SL *ps);
// 检查空间
bool CheckSize(SL *ps);
// 尾插
void SLPushBack(SL *ps, SLDatatype x);
// 头插
void SLPushFront(SL *ps, SLDatatype x);
// 头删
void SLPopFront(SL *ps);
// 尾删
void SLPopBack(SL *ps);
// 顺序表查找
int SLFind(SL *ps, SLDatatype x);
// 在pos位置插入数据
void SLInsert(SL *ps, int pos, SLDatatype x);
// 删除顺序表在pos位置的数据
void SLErase(SL *ps, int pos);