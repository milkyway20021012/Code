#include "../include/heap.h"

// int main()
// {
//     HP hp;
//     HeapInit(&hp);
//     HeapPush(&hp, 4);
//     HeapPush(&hp, 18);
//     HeapPush(&hp, 42);
//     HeapPush(&hp, 12);
//     HeapPush(&hp, 2);
//     HeapPush(&hp, 3);
//     // HeapSort(&hp.a, hp.size - 1);
//     while (!HeapEmpty(&hp))
//     {
//         printf("%d ", HeapTop(&hp));
//         HeapPop(&hp);
//     }
//     printf("\n");
//     return 0;
// }

// 堆排序的概念 -- 排升序 -> 建大堆 排降序 -> 建小堆
void HeapSort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        AdjustUp(a, i); // 建堆
    }
    // 升序
    while (n >= 0)
    {
        Swap(&a[0], &a[n]);  // 因爲是排升序 堆頂數據一定是最大的
        AdjustDown(a, n, 0); // 調整後可能會導致整個堆不是堆 所以要去調整
        n--;
    }
}
// 堆排序時間複雜度：O(nlogn)

void PrintTopk(const char *file, int k)
{
    // 1. 建堆 -- 用前k個數據建堆
    int *topk = (int *)malloc(sizeof(int) * k);
    if (topk == NULL)
    {
        perror("malloc fail");
        return;
    }
    FILE *fout = fopen(file, "r");
    if (fout == NULL)
    {
        perror("fopen fail");
        return;
    }
    // 讀出前k個建堆
    for (int i = 0; i < k; i++)
    {
        fscanf(fout, "%d", &topk[i]);
    }
    for (int i = (k - 2) / 2; i >= 0; --i)
    {
        AdjustDown(topk, k, i);
    }
    int val = 0;
    int ret = fscanf(fout, "%d", &val);
    while (ret != EOF)
    {
        if (val > topk[0])
        {
            topk[0] = val;
            AdjustDown(topk, k, 0);
        }
        ret = fscanf(fout, "%d", &val);
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d ", topk[i]);
    }
    printf("\n");
    free(topk);
    fclose(fout);

    // 2. 將剩餘的n-k個數據依次與堆頂數據進行比較，如果比堆頂元素大取代之並向下調整
}
void CreateNData()
{
    int n = 10000000;
    srand(time(0));
    const char *file = "data.txt";
    FILE *fin = fopen(file, "w");
    if (fin == NULL)
    {
        perror("fopen fail");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 10000;
        fprintf(fin, "%d\n", x);
    }
    fclose(fin);
}
// int main()
// {
//     int arr[] = {2, 3, 6, 2, 1, 5, 8, 4, 3};
//     size_t sz = sizeof(arr) / sizeof(arr[0]);
//     printf("排序前：");
//     for (int i = 0; i < sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n排序後:");
//     HeapSort(arr, sz - 1);
//     for (int i = 0; i < sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     return 0;
// }

// int main()
// {
//     // CreateNData();
//     PrintTopk("data.txt", 10);
//     return 0;
// }

int main(){
    int array[] = {27,15,19,18,28,34,65,49,25,37};
    


    return 0;
}