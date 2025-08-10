#include "../include/heap.h"
#include <string.h>

// 默认初始化堆
void HPInit(HP *php) {
  php->_a = (HPDataType *)malloc(sizeof(HPDataType) * 4);
  if (php->_a == NULL) {
    perror("malloc fail:");
    return;
  }
  php->_capacity = 4;
  php->_size = 0;
}
// 堆的销毁
void HPDestroy(HP *php) {
  assert(php);
  free(php->_a);
  php->_a = NULL;
  php->_capacity = php->_size = 0;
  printf("销毁成功！\n");
}
// 打印
void HPPrint(HP *php) {
  for (int i = 0; i < php->_size; ++i) {
    printf("%d ", php->_a[i]);
  }
  printf("\n");
}
// 堆的插入
void HPPush(HP *php, HPDataType x) {
  assert(php);
  // 建小堆
  if (php->_size == php->_capacity) {
    HPDataType *tmp = realloc(php->_a, sizeof(HPDataType) * php->_capacity * 2);
    if (tmp == NULL) {
      perror("realloc fail:");
      return;
    }
    php->_a = tmp;
    php->_capacity *= 2;
  }
  php->_a[php->_size] = x;
  // 向上调整
  AdjustUp(php->_a, php->_size);
  php->_size++;
}
// 向上调整算法
void AdjustUp(HPDataType *a, int child) {
  int parent = (child - 1) / 2;
  while (child > 0) {
    if (a[child] < a[parent]) {
      int tmp = a[child];
      a[child] = a[parent];
      a[parent] = tmp;
    }
    child = parent;
    parent = (child - 1) / 2;
  }
}
// 向下调整算法
void AdjustDown(HPDataType *a, int n, int parent) {
  int child = 2 * parent + 1;
  while (child < n) {
    int right = child + 1;
    if (right < n && a[right] < a[child]) {
      child = right;
    }
    if (a[child] < a[parent]) {
      HPDataType tmp = a[child];
      a[child] = a[parent];
      a[parent] = tmp;
    } else {
      break;
    }
    parent = child;
    child = 2 * parent + 1;
  }
}
// 利⽤给定数组初始化堆
void HPInitArray(HP *php, HPDataType *a, int n) {
  assert(php->_a && a);
  for (int i = 0; i < n; ++i) {
    php->_a[i] = a[i];
    AdjustUp(php->_a, php->_size);
  }
}
// 判空
bool HPEmpty(HP *php) {
  assert(php);
  return php->_size == 0;
}
// 求size
int HPSize(HP *php) {
  assert(php);
  return php->_size;
}
// 获取堆顶元素
HPDataType HPTop(HP *php) {
  assert(php && php->_a && php->_size > 0);
  return php->_a[0];
}
// 删除堆顶的数据
void HPPop(HP *php) {
  assert(php && php->_a && php->_size > 0);
  php->_a[0] = php->_a[php->_size - 1];
  --php->_size;
  if (php->_size > 0) {
    AdjustDown(php->_a, php->_size, 0);
  }
}

// void HeapSort(HP *php) {
//   assert(php);
//   while (!HPEmpty(php)) {
//     printf("%d ", HPTop(php));
//     HPPop(php);
//   }
//   printf("\n");
// }