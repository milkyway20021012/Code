#include <stdio.h>
#include <stdlib.h>
// 插入排序
void InsertSort(int *a, int n);
// 希尔排序
void ShellSort(int *a, int n);
// 选择排序
void SelectionSort(int *a, int n);
// 冒泡排序
void BubbleSort(int *a, int n);
// 快速排序(递归版)
int _QuickSort(int *a, int left, int right);
// 非递归版本
void QuickSortNonR(int *a, int left, int right);
void QuickSort(int *a, int left, int right);
// 归并排序
void MergeSort(int *a, int left, int right, int *tmp);
void Merge(int *a, int n);
// 计数排序
void CountSort(int *a, int n);