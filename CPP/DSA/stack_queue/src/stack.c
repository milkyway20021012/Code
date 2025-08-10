#include "../include/stack.h"

// 初始化栈
void STInit(ST *ps) {
  if (ps == NULL) {
    fprintf(stderr, "STInit: ps is NULL\n");
    return;
  }
  ps->_a = (STDataType *)malloc(sizeof(STDataType) * 4);
  if (ps->_a == NULL) {
    perror("ps->_a malloc fail:");
    return;
  }
  ps->_capacity = 4;
  ps->_size = 0;
}
// 检查Capacity
void CheckCapacity(ST *ps) {
  if (ps->_size == ps->_capacity) {
    STDataType *tmp =
        (STDataType *)realloc(ps->_a, sizeof(int) * 2 * ps->_capacity);
    if (tmp == NULL) {
      perror("realloc fail:");
      return;
    }
    ps->_a = tmp;
  }
}
// ⼊栈
void STPush(ST *ps, STDataType x) {
  assert(ps);
  CheckCapacity(ps);
  ps->_a[ps->_size] = x;
  ps->_size++;
}
// 出栈
void STPop(ST *ps) {
  assert(ps);
  --ps->_size;
}
// 取栈顶元素
STDataType STTop(ST *ps) {
  assert(ps);
  return ps->_a[ps->_size - 1];
}
// 获取栈中有效元素个数
int STSize(ST *ps) {
  assert(ps);
  return ps->_size;
}
// 栈是否为空
bool STEmpty(ST *ps) { return ps->_size == 0; }