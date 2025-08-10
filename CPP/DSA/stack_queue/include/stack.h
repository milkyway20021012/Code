#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int STDataType;
typedef struct stack {
  STDataType *_a;
  STDataType _capacity;
  STDataType _size;
} ST;
// 初始化栈
void STInit(ST *ps);
// 销毁栈
void STDestroy(ST *ps);
// 检查capacity
void CheckCapacity(ST *ps);
// ⼊栈
void STPush(ST *ps, STDataType x);
// 出栈
void STPop(ST *ps);
// 取栈顶元素
STDataType STTop(ST *ps);
// 获取栈中有效元素个数
int STSize(ST *ps);
// 栈是否为空
bool STEmpty(ST *ps);