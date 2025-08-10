#include <iostream>
using namespace std;

// // 计算Func2的时间复杂度？
// void Func2(int N) {
//   int count = 0;
//   for (int k = 0; k < 2 * N; ++k) { // ---这个 for 会运行 2N 次
//     ++count;
//   }
//   int M = 10;
//   while (M--) { // --- while 会运行 10 次
//     ++count;
//   }
//   // 所以时间复杂度应该是 2N + 10 根据规则如果系数不是 1
//   可以忽略，常数项可以忽略 --- 所以是 O(N) printf("%d\n", count);
// }

// 计算Func3的时间复杂度？
// void Func3(int N, int M) {
//   int count = 0;
//   for (int k = 0; k < M; ++k) { // M次
//     ++count;
//   }
//   for (int k = 0; k < N; ++k) { // N次
//     ++count;
//   }
//   /*这段程式码的严格时间复杂度是 O(M + N)。 如果题目规定 M 与 N
//   同级（或M是常数），可以简化成 O(N)
//     如果 M 远大于 N，则应该以 M 为主，时间复杂度近似 O(M) */
//   printf("%d\n", count);
// }

// // 计算Func4的时间复杂度？
// void Func4(int N) {
//   int count = 0;
//   for (int k = 0; k < 100; ++k) { // 运行100次
//     ++count;
//   }
//   // T(100) --- O(1)
//   printf("%d\n", count);
// }

// 计算strchr的时间复杂度？
// const char *strchr(const char *str, int character) {
//   const char *p_begin = s;
//   while (*p_begin != character) {
//     if (*p_begin == '\0')
//       return NULL;
//     p_begin++;
//   }
//   return p_begin;
// }
/*
strchr执⾏的基本操作次数：
1）若要查找的字符在字符串第⼀个位置，则：T (N) = 1
2）若要查找的字符在字符串最后的⼀个位置，则：T (N) = N
3）若要查找的字符在字符串中间位置，则：
 T (N) = N/2
因此：strchr的时间复杂度分为：
最好情况： O(1)
最坏情况： O(N)
平均情况： O(N)
*/

// void BubbleSort(int *a, int n) {
//   assert(a);
//   for (size_t end = n; end > 0; --end) {
//     int exchange = 0;
//     for (size_t i = 1; i < end; ++i) {
//       if (a[i - 1] > a[i]) {
//         Swap(&a[i - 1], &a[i]);
//         exchange = 1;
//       }
//     }
//     if(exchange == 0) break;
//   }
// }

// 计算阶乘递归Fac的空间复杂度？
// long long Fac(size_t N) {
//   if (N == 0)
//     return 1;
//   return Fac(N - 1) * N;
// }