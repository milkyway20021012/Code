#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 4  // 初始空间大小

typedef struct SeqList {
  int *_a;
  size_t _capacity;
  size_t _size;

} SL;

// 顺序表初始化
void SLInit(SL *sp);
// 顺序表销毁
void SLDestroy(SL *sp);
// 顺序表打印
void SLPrint(SL *sp);
// 顺序表尾插
void SLPush_back(SL *sp, int x);
// 顺序表删除
void SLPop_back(SL *sp);
// 顺序表头插
void SLPush_front(SL *sp, int x);
// 顺序表头删
void SLPop_front(SL *sp);
// 指定位置之前插⼊/删除数据
void SLInsert(SL *sp, size_t pos, int x);
// 指定位置删除
void SLErase(SL *sp, size_t pos);
// 查找
int SLfind(SL *sp, int x);
