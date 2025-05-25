#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h> 
// 以順序表實現堆

typedef int HeapDatatype;

typedef struct Heap
{
    HeapDatatype *a; // 用來創建數組
    int capacity;    // 容量
    int size;        // 有效數據個數
} HP;

// 初始化
void HeapInit(HP *php);
// 初始化數組
void HeapInitArray(HP *php, int *a, int n);
// 交換
void Swap(HeapDatatype *x1, HeapDatatype *x2);
// 向上調整
void AdjustUp(HeapDatatype *a, int child);
// 向下調整
void AdjustDown(HeapDatatype *a, int n, int parent);
// 插入數據
void HeapPush(HP *php, HeapDatatype x);
// 刪除數據
void HeapPop(HP *php);
// 取堆頂數據
HeapDatatype HeapTop(HP *php);
// 判斷堆是否為空
bool HeapEmpty(HP *php);
// 堆有效數據的個數
int HeapSize(HP *php);
// 堆銷毀
void HeapDestroy(HP *php);