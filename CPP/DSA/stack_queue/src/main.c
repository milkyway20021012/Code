#include "../include/queue.h"
#include "../include/stack.h"

int main() {
  // ST st;
  // STInit(&st);
  // for (size_t i = 0; i < 10; ++i) {
  //   STPush(&st, i);
  // }
  // while (!STEmpty(&st)) {
  //   int top = STTop(&st);
  //   printf("%d ", top);
  //   STPop(&st);
  // }
  // printf("\n");

  Queue qu;
  QueueInit(&qu);
  QueuePush(&qu, 1);
  QueuePush(&qu, 2);
  QueuePush(&qu, 3);
  QueuePush(&qu, 4);
  QueuePush(&qu, 5);
  QueuePush(&qu, 6);
  // while (!QueueEmpty(&qu)) {
  //   int top = QueueFront(&qu);
  //   printf("%d\n", top);
  //   QueuePop(&qu);
  //   printf("剩余数据个数：%d\n", QueueSize(&qu));
  // }
  QueueDestroy(&qu);
  return 0;
}