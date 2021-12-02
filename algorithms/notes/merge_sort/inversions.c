// Author: Shihao Liu
// Date: 2021-12-02


// 解决逆序对问题 (通过修改归并排序算法)

/**
 * 概念:
 *  A[1...n]是含n个元素的数组, 若i < j 且A[i] > A[j], 则称(i, j)为一个逆序对.
 *
 * 问题描述:
 *  给定一个含n个元素的数组nums, 统计其中逆序对的个数.
*/

#include <stdio.h>
#include <stdlib.h>

/** 归并排序算法 (已调整)
 * @param nums 待处理数组
 * @param p 待排序区间的起始下标
 * @param r 待排序区间的结束下标
 * @param count 指向逆序对个数的累积值的指针
 * @return 将nums[p...r]中的元素按非降序排序, 排序后的元素仍保存在nums[p...r]中
 */
void MergeSort(int nums[], int p, int r, int *count);

/** 归并操作 (已调整)
 * @param nums 待处理数组
 * @param p 左侧有序部分的起始下标
 * @param q 左侧有序部分的结束下标
 * @param r 右侧有序部分的结束下标
 * @param count 指向逆序对个数的累积值的指针
 * @return 将有序序列nums[p...q]和有序序列nums[q+1...r]合并, 且仍然保持有序. 处理结果
 * 保存在nums[p...r]区间内.
 */
void Merge(int nums[], int p, int q, int r, int *count);

/** 计算逆序对个数
 * @param nums 待处理数组
 * @param n 数组元素个数
 * @return 返回nums中的逆序对个数
 */
int Inversions(int nums[], int n);


/******************** Implementations *****************************/

void MergeSort(int nums[], int p, int r, int *count) {
  if (p < r) {
    int q = (p + r) / 2;
    MergeSort(nums, p, q, count);
    MergeSort(nums, q + 1, r, count);
    Merge(nums, p, q, r, count);
  }
}

void Merge(int nums[], int p, int q, int r, int *count) {
  // 计算左右两侧有序子列的长度
  int len1 = q - p + 1, len2 = r - q;
  // 创建两个辅助数组, 多分配的一个位置用于放置哨兵
  int *left = (int *)malloc((len1 + 1) * sizeof(int));
  int *right = (int *)malloc((len2 + 1) * sizeof(int));
  int i, j;
  for (i = 0; i < len1; i++) {
    left[i] = nums[p + i];
  }
  for (i = 0; i < len2; i++) {
    right[i] = nums[q + 1 + i];
  }
  left[len1] = INT_MAX;   // 设置哨兵
  right[len2] = INT_MAX;  // 设置哨兵
  i = 0;
  j = 0;
  for (int k = p; k <= r; k++) {
    if (left[i] > right[j]) {
      (*count) += len1 - i;  // !!! 在这里更新count所指向的内容
      nums[k] = right[j];
      j++;
    } else {
      nums[k] = left[i];
      i++;
    }
  }
  free(left);
  free(right);
}

int Inversions(int nums[], int n) {
  int count;
  MergeSort(nums, 0, n - 1, &count);
  return count;
}

int main() {
  int nums[8] = {8, 7, 6, 5, 4, 3, 2, 1};
  printf("Inversions count: %d\n", Inversions(nums, 8)); // 28
}