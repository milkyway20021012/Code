// #include "../include/heap.h"
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// // bool IsMinHeapHP(const HP *php) {
// //   for (int child = 1; child < php->_size; ++child) {
// //     int parent = (child - 1) / 2;
// //     if (php->_a[parent] > php->_a[child])
// //       return false;
// //   }
// //   return true;
// // }
// // bool IsMinHeapArray(const HPDataType *a, int n) {
// //   for (int child = 1; child < n; ++child) {
// //     int parent = (child - 1) / 2;
// //     if (a[parent] > a[child])
// //       return false;
// //   }
// //   return true;
// // }
// // 数组的Heap Sort
// // void HeapSort(int *a, int n) {
// //   for (int i = (n - 1 - 1) / 2; i > 0; --i) {
// //     AdjustDown(a, n, i);
// //   }
// //   int end = n - 1;
// //   while (end > 0) {
// //     printf("%d ", a[0]);
// //     a[0] = a[end];
// //     --end;
// //     AdjustDown(a, end, 0);
// //   }
// //   printf("\n");
// // }
// void CreateNDate() {
//   // 造数据
//   int n = 100000;
//   srand(time(0));
//   const char *file = "data.txt";
//   FILE *fin = fopen(file, "w");
//   if (fin == NULL) {
//     perror("fopen error");
//     return;
//   }
//   for (int i = 0; i < n; ++i) {
//     int x = (rand() + i) % 1000000;
//     fprintf(fin, "%d\n", x);
//   }
//   fclose(fin);
// }
// void topk() {
//   printf("请输⼊k：");
//   int k = 0;
//   scanf("%d", &k);
//   const char *file = "data.txt";
//   FILE *fout = fopen(file, "r");
//   if (fout == NULL) {
//     perror("fopen error");
//     return;
//   }
//   int val = 0;
//   int *minheap = (int *)malloc(sizeof(int) * k);
//   if (minheap == NULL) {
//     perror("malloc error");
//     return;
//   }
//   for (int i = 0; i < k; i++) {
//     fscanf(fout, "%d", &minheap[i]);
//   }
//   // 建k个数据的⼩堆
//   for (int i = (k - 1 - 1) / 2; i > 0; i--) {
//     AdjustDown(minheap, k, i);
//     int x = 0;
//     while (fscanf(fout, "%d", &x) != EOF) {
//       // 读取剩余数据，⽐堆顶的值⼤，就替换他进堆
//       if (x > minheap[0]) {
//         minheap[0] = x;
//         AdjustDown(minheap, k, 0);
//       }
//     }
//     for (int i = 0; i < k; i++) {
//       printf("%d ", minheap[i]);
//     }
//     fclose(fout);
//   }
// }
// int main(void) {
//   // // 測試 HPInit
//   HP hp;
//   HPInit(&hp);
//   srand((unsigned)time(NULL));
//   int count = 16; // 插入16筆資料
//   printf("[Test] HPPush 隨機插入 %d 筆資料:\n", count);
//   for (int i = 0; i < count; ++i) {
//     int x = rand() % 100; // 0~99 的非有序亂數
//     HPPush(&hp, x);
//   }
//   HPPrint(&hp);
//   printf("%d", HPSize(&hp));
//   printf("\n");
//   // HeapSort(hp._a, hp._size);
//   HPDestroy(&hp);
//   return 0;
// }

#include "../include/bin_tree.h"
#include "../include/queue.h"

int main() {
  BTNode *_root = CreateTree();

  // 测试队列能否正确处理 BTNode* 类型
  Queue q;
  QueueInit(&q);

  // 测试 QueuePush 和 QueueFront
  QueuePush(&q, _root);
  BTNode *front_node = QueueFront(&q);
  printf("队列前端节点数据: %d\n", front_node->_data);

  // 测试层序遍历
  printf("层序遍历结果: ");
  LevelOrder(_root);
  printf("\n");

  QueueDestroy(&q);
  BinaryTreeDestory(&_root);
  return 0;
}