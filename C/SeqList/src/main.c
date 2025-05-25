#include "../include/SeqList.h"
void SeqTest1()
{
    SL *plist;
    SLInit(plist);
    SLPushBack(plist, 1);
    SLPushBack(plist, 2);
    SLPushBack(plist, 3);
    SLPushBack(plist, 4);
    SLPushBack(plist, 5);
    SLPushFront(plist, 0);
    SLPushFront(plist, -1);
    SLPushFront(plist, -2);
    SLPushFront(plist, -3);
    SLPushFront(plist, -4);
    SLPrint(plist);
    SLInsert(plist, 5, 4);
    SLPrint(plist);
    SLErase(plist, 4);
    SLPrint(plist);
    SLDestroy(plist);
}

int main()
{
    SeqTest1();
    return 0;
}