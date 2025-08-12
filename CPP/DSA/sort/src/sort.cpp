#include "../include/sort.h"

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
// 插入排序
void InsertSort(int *a, int n) {
  for (int i = 1; i < n; ++i) {
    // 已经排序的最后一个位置
    int end = i - 1;
    // 待插入数据
    int tmp = a[i];
    while (end >= 0 && a[end] > tmp) {
      a[end + 1] = a[end];
      --end;
    }
    a[end + 1] = tmp;
  }
}
// 希尔排序
void ShellSort(int *a, int n) {
  int gap = n;
  while (gap > 1) {
    gap = gap / 3 + 1;

    for (int i = gap; i < n; ++i) {
      int tmp = a[i];
      int end = i - gap;

      while (end >= 0 && a[end] > tmp) {
        a[end + gap] = a[end];
        end -= gap;
      }
      a[end + gap] = tmp;
    }
  }
}

// 选择排序
void SelectionSort(int *a, int n) {
  for (int i = 0; i < n; ++i) {
    int minIndex = i; // 假設 i 是最小值位置
    for (int j = i + 1; j < n; ++j) {
      if (a[j] < a[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      swap(&a[i], &a[minIndex]);
    }
  }
}
// 冒泡排序
void BubbleSort(int *a, int n) {
  for (int i = 0; i < n; ++i) {
    int exchange = 0;
    for (int j = 0; j < n - i - 1; ++j) {
      if (a[j] > a[j + 1]) {
        exchange = 1;
        swap(&a[j], &a[j + 1]);
      }
    }
    if (!exchange) {
      break;
    }
  }
}
// 快速排序(递归版)
// 1. hoare版本 --- 左起步
// int _QuickSort(int *a, int left, int right) {
//   int begin = left;
//   int end = right;
//   int _key = left;
//   ++begin;
//   while (begin <= end) {
//     while (begin <= end && a[begin] < a[_key]) {
//       ++begin;
//     }
//     while (begin <= end && a[end] > a[_key]) {
//       --end;
//     }
//     if (begin <= end) {
//       swap(&a[begin++], &a[end--]);
//     }
//   }
//   swap(&a[_key], &a[end]); // 把 pivot 放到正確位置
//   return end;              // 返回 pivot 的新位置
// }

// // 2. 挖坑版本
// int _QuickSort(int *a, int left, int right) {
//   // 5 1 4 9 6
//   int pivotVal = a[left]; // 把基準值暫存起來（挖坑）
//   int hole = left;        // 當前的坑位置
//   while (left < right) {
//     // 從右邊找比基準小的，填到左邊的坑
//     while (left < right && a[right] >= pivotVal) {
//       --right;
//     }
//     a[hole] = a[right]; // 右邊找到後填坑
// ;    hole = right;       // 新坑位置在剛剛移動的地方
//     // 從左邊找比基準大的，填到右邊的坑
//     while (left < right && a[left] <= pivotVal) {
//       ++left;
//     }
//     a[hole] = a[left]; // 左邊找到後填坑
//     hole = left;       // 新坑位置在剛剛移動的地方
//   }
//   // 最後把基準值填回最後的坑
//   a[hole] = pivotVal;
//   return hole; // 返回基準的最終位置
// }

// // 3. lomuto前后指针版本
int _QuickSort(int *a, int left, int right) {
  int _prev = left;
  int _key = left; // key的位置
  int _cur = left + 1;
  while (_cur <= right) {
    if (a[_cur] < a[_key] && ++_prev != _cur) {
      swap(&a[_prev], &a[_cur]);
    }
    ++_cur;
  }
  swap(&a[_key], &a[_prev]);
  return _prev;
}
// void QuickSortNonR(int *a, int left, int right) {
//   ST st;
//   STInit(&st);
//   STPush(&st, right);
//   STPush(&st, left);
//   while (!STEmpty(&st)) {
//     int begin = STTop(&st);
//     STPop(&st);
//     int end = STTop(&st);
//     STPop(&st);
//     // 单趟
//     int keyi = begin;
//     int prev = begin;
//     int cur = begin + 1;
//     while (cur <= end) {
//       if (a[cur] < a[keyi] && ++prev != cur)
//         swap(&a[prev], &a[cur]);
//       ++cur;
//     }
//     swap(&a[keyi], &a[prev]);
//     keyi = prev;
//     // [begin, keyi-1] keyi [keyi+1, end]
//     if (keyi + 1 < end) {
//       STPush(&st, end);
//       STPush(&st, keyi + 1);
//     }
//     if (begin < keyi - 1) {
//       STPush(&st, keyi - 1);
//       STPush(&st, begin);
//     }
//   }
//   STDestroy(&st);
// }
void QuickSort(int *a, int left, int right) {
  if (left >= right) {
    return;
  }
  int _meet = _QuickSort(a, left, right);
  QuickSort(a, left, _meet - 1);
  QuickSort(a, _meet + 1, right);
}
// 归并排序
void MergeSort(int *a, int left, int right, int *tmp) {
  if (left >= right) {
    return;
  }
  int mid = (left + right) / 2;
  MergeSort(a, left, mid, tmp);
  MergeSort(a, mid + 1, right, tmp);
  // 合并
  int begin1 = left, end1 = mid;
  int begin2 = mid + 1, end2 = right;
  int index = left;
  while (begin1 <= end1 && begin2 <= end2) {
    if (a[begin1] <= a[begin2]) {
      tmp[index++] = a[begin1++];
    } else {
      tmp[index++] = a[begin2++];
    }
  }
  while (begin1 <= end1) {
    tmp[index++] = a[begin1++];
  }
  while (begin2 <= end2) {
    tmp[index++] = a[begin2++];
  }

  for (int i = left; i <= right; ++i) {
    a[i] = tmp[i];
  }
}
void Merge(int *a, int n) {
  int *tmp = new int[n];
  MergeSort(a, 0, n - 1, tmp);
  delete[] tmp;
}
// 计数排序
void CountSort(int *a, int n) {
  int max = a[0], min = a[0];
  // 先找最大和最小的值
  for (int i = 0; i < n; ++i) {
    if (a[i] > max) {
      max = a[i];
    }
    if (a[i] < min) {
      min = a[i];
    }
  }
  // 在来开空间存放计数
  int *count = (int *)calloc(max - min + 1, sizeof(int));
  // 计数
  for (int i = 0; i < n; ++i) {
    count[a[i] - min]++;
  }
  // 将计数结果放回原数组
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (count[i]--) {
      a[j++] = i + min;
    }
  }
}