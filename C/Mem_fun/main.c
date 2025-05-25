#include <stdio.h>
#include <string.h>
// 与内存相关的函数需要包含 <string.h>
/*
1. memcpy : 意即将 num 个字节从 source 拷贝至 destination

函数原型：void* memcpy(void* destination, void* source, size_t num);

destination : Pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
source : Pointer to the source of data to be copied, type-casted to a pointer of type const void*.
num :Number of bytes to copy.

当 memcpy 遇到 '/0' 不会停止，如果 source 和 destination 有重叠部分，则复制的结果都会是未定义

*/

/*
2.  memmove ： 和memcpy 作用相同，差别在memmove 可以解决内存重叠的问题
函数原型：void * memmove ( void * destination, const void * source, size_t num );

destination : Pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
source : Pointer to the source of data to be copied, type-casted to a pointer of type const void*.
num :Number of bytes to copy.

和memcpy 的差别在 memmove 的 source 和 destination 的内存块可以重叠


*/

// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int arr2[10] = {0};

//     memcpy(arr1+1, arr1,36);
//     for (int i = 0; i < 10; ++i)
//     {
//         printf("%d ", arr1[i]);
//     }
//     return 0;
// }

void *my_memmove(void *dst, const void *src, size_t count)
{
    void *ret = dst;
    if (dst <= src || (char *)dst >= ((char *)src + count))
    {
        /*
         * Non-Overlapping Buffers
         * copy from lower addresses to higher addresses
         */
        while (count--)
        {
            *(char *)dst = *(char *)src;
            dst = (char *)dst + 1;
            src = (char *)src + 1;
        }
    }
    else
    {
        /*
         * Overlapping Buffers
         * copy from higher addresses to lower addresses
         */
        dst = (char *)dst + count - 1;
        src = (char *)src + count - 1;
        while (count--)
        {
            *(char *)dst = *(char *)src;
            dst = (char *)dst - 1;
            src = (char *)src - 1;
        }
    }
    return (ret);
}

// int main()
// {
//     char arr[] = "1234567890";

//     // 这将导致内存重叠，源和目标部分是相同的
//     memmove(arr + 2, arr, 6); // 将 "123456" 复制到 "345678"

//     printf("arr = %s\n", arr); // 输出会导致未定义行为

//     return 0;
// }

int main()
{
    char arr[] = "1234567890";

    // 这将导致内存重叠，源和目标部分是相同的
    memcpy(arr + 2, arr, 6); // 将 "123456" 复制到 "345678"

    printf("arr = %s\n", arr); // 输出会导致未定义行为

    return 0;
}