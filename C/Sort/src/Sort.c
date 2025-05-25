#include "../include/Sort.h"
void Print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void InsertSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int end = i - 1;
        int tmp = a[i];

        while (end >= 0)
        {
            if (tmp < a[end])
            {
                a[end + 1] = a[end];
                --end;
            }
            else
            {
                break;
            }
        }
        a[end + 1] = tmp;
    }
}
/*
插入排序分析
時間複雜度：O(n^2) -- 最壞情況
空間複雜度：O(1)
當數據的排序接近有序時，插入排序的效率才會比較高 -- O(n)
*/
void ShellSort(int *a, int n)
{
    // int gap = 3; // 讓gap是動態的
    int gap = n;
    while (gap > 1)
    {
        gap /= 2;
        for (int j = 0; j < gap; j++)
        {
            for (int i = j; i < n - gap; i += gap)
            {

                int end = i;
                int tmp = a[end + gap];
                while (end >= 0)
                {
                    if (tmp < a[end])
                    {
                        a[end + gap] = a[end];
                        end -= gap;
                    }
                    else
                    {
                        break;
                    }
                }
                a[end + gap] = tmp;
            }
        }
        // Print(a,n);
    }
}
/*
希爾排序分析
時間複雜度：O(n^1.3)


*/