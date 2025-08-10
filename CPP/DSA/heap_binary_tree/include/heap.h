#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef int HPDataType;
typedef struct Heap {
  HPDataType *_a;
  int _size;
  int _capacity;
} HP;
// 默认初始化堆
void HPInit(HP *php);
// 打印
void HPPrint(HP *php);
// 利⽤给定数组初始化堆
void HPInitArray(HP *php, HPDataType *a, int n);
// 堆的销毁
void HPDestroy(HP *php);
// 堆的插⼊
void HPPush(HP *php, HPDataType x);
// 获取堆顶
HPDataType HPTop(HP *php);
// 删除堆顶的数据
void HPPop(HP *php);
// 判空
bool HPEmpty(HP *php);
// 求size
int HPSize(HP *php);
// 向上调整算法
void AdjustUp(HPDataType *a, int child);
// 向下调整算法
void AdjustDown(HPDataType *a, int n, int parent);
// 排序
// void HeapSort(HP *php);