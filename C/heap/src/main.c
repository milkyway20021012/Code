#include "../include/heap.h"

int main()
{
    HP hp;
    HeapInit(&hp);
    HeapPush(&hp, 4);
    HeapPush(&hp, 18);
    HeapPush(&hp, 42);
    HeapPush(&hp, 12);
    HeapPush(&hp, 2);
    HeapPush(&hp, 3);

    // HeapSort(&hp.a, hp.size - 1);

    while (!HeapEmpty(&hp))
    {
        printf("%d ", HeapTop(&hp));
        HeapPop(&hp);
    }
    printf("\n");
    return 0;
}