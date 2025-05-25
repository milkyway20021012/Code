#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// 单链表的实现
typedef int SLDatatype;

typedef struct SList{
    SLDatatype data;
    struct SList* next;
}SL;


