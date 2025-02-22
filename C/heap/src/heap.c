#include "../include/heap.h"

// 這裡的堆以大根堆來進行演示

void Swap(HeapDatatype *x1, HeapDatatype *x2)
{
    HeapDatatype tmp = *x1;
    *x1 = *x2;
    *x2 = tmp;
}

void HeapInit(HP *php)
{
    assert(php);
    php->a = (HeapDatatype *)malloc(sizeof(HeapDatatype) * 4);
    if (php->a == NULL)
    {
        perror("malloc fail");
    }
    php->capacity = 4;
    php->size = 0;
}

// 建堆 （插入）（向上調整）

void AdjustUp(HeapDatatype *a, int child)
{
    int parent = (child - 1) / 2;
    while (child > 0)
    {
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
        {
            break;
        }
    }
}

// 堆的刪除 （將根節點與葉子進行交換再向下調整）
// 向下調整的前提是子樹必須要是大根堆或小根堆

void AdjustDown(HeapDatatype *a, int n, int parent) // n是數組中有效數據的個數
{
    int child = 2 * parent + 1;
    while (child < n)
    {
        // 先選出左右孩子哪個比較大
        if (child + 1 < n && a[child] < a[child + 1])
        {
            ++child;
        }
        if (a[parent] < a[child])
        {
            Swap(&a[parent], &a[child]);
            parent = child;
            child = 2 * parent + 1;
        }
        else
        {
            break;
        }
    }
}
// 插入數據
void HeapPush(HP *php, HeapDatatype x)
{
    assert(php);
    if (php->capacity == php->size)
    {
        HeapDatatype *tmp = (HeapDatatype *)realloc(php->a, sizeof(HeapDatatype) * 2 * php->capacity);
        if (tmp == NULL)
        {
            perror("relloc fail");
        }
        php->a = tmp;
    }

    php->a[php->size++] = x;
    AdjustUp(php->a, php->size - 1);
}
// 刪除數據
void HeapPop(HP *php)
{
    assert(php);
    Swap(&php->a[0], &php->a[php->size - 1]);
    php->size--;
    AdjustDown(php->a, php->size, 0);
}

// 取堆頂數據
HeapDatatype HeapTop(HP *php)
{
    assert(php);
    return php->a[0];
}
// 判斷堆是否為空

bool HeapEmpty(HP *php)
{
    assert(php);
    return php->size == 0;
}
// 堆有效數據個數
int HeapSize(HP *php)
{
    assert(php);
    return php->size;
}