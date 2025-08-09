// #include "../include/seqlist.h"

// #include <assert.h>

// // 顺序表初始化
// void SLInit(SL *sp) {
//   assert(sp);  // sp 不能为空
//   sp->_a = (int *)malloc(sizeof(int) * INITIAL_CAPACITY);
//   if (sp->_a == NULL) {
//     perror("malloc fail:");
//     return;
//   }
//   sp->_capacity = INITIAL_CAPACITY;
//   sp->_size = 0;
// }
// // 顺序表销毁
// void SLDestroy(SL *sp) {
//   assert(sp);
//   free(sp->_a);
//   sp->_a = NULL;
//   sp->_capacity = 0, sp->_size = 0;
// }
// // 顺序表打印
// void SLPrint(SL *sp) {
//   assert(sp);
//   for (size_t i = 0; i < sp->_size; ++i) {
//     printf("%d ", sp->_a[i]);
//   }
//   printf("\n");
// }

// // 顺序表扩容
// void CheckCapacity(SL *sp) {
//   assert(sp);
//   if (sp->_size == sp->_capacity) {
//     int *tmp = (int *)realloc(sp->_a, sizeof(int) * sp->_capacity * 2);  // realloc 可以实现自动分配新空间并拷贝旧数据
//     if (tmp == NULL) {
//       perror("realloc error:");
//       return;
//     }
//     sp->_a = tmp;
//     sp->_capacity *= 2;
//   }
// }

// // 顺序表尾插
// void SLPush_back(SL *sp, int x) {
//   assert(sp);
//   CheckCapacity(sp);
//   sp->_a[sp->_size++] = x;
// }
// // 顺序表删除
// void SLPop_back(SL *sp) {
//   assert(sp || sp->_size != 0);
//   --sp->_size;
// }

// // 顺序表头插
// void SLPush_front(SL *sp, int x) {
//   assert(sp);
//   CheckCapacity(sp);
//   for (size_t i = sp->_size; i > 0; --i) {
//     sp->_a[i] = sp->_a[i - 1];
//   }
//   sp->_a[0] = x;
//   sp->_size++;
// }

// // 顺序表头删
// void SLPop_front(SL *sp) {
//   assert(sp && sp->_size != 0);
//   for (size_t i = 0; i < sp->_size; ++i) {
//     sp->_a[i] = sp->_a[i + 1];
//   }
//   sp->_size--;
// }
// // 指定位置之前插⼊/删除数据
// void SLInsert(SL *sp, size_t pos, int x) {
//   assert(sp && pos <= sp->_size);  // pos 不能超过当前大小
//   CheckCapacity(sp);
//   for (size_t i = sp->_size; i >= pos; --i) {
//     sp->_a[i] = sp->_a[i - 1];
//   }
//   sp->_a[pos - 1] = x;
//   sp->_size++;
// }
// // 指定位置删除
// void SLErase(SL *sp, size_t pos) {
//   assert(sp && pos <= sp->_size);
//   for (size_t i = pos - 1; i < sp->_size - 1; ++i) {
//     sp->_a[i] = sp->_a[i + 1];
//   }
//   sp->_size--;
// }
// // 查找
// int SLfind(SL *sp, int x) {
//   assert(sp);
//   for (size_t i = 0; i < sp->_size; ++i) {
//     if (sp->_a[i] == x) {
//       printf("%d的值在index为%zu的位置!\n", x, i);
//       return i;
//     }
//   }
//   printf("%d的值不存在\n", x);
//   return -1;
// }