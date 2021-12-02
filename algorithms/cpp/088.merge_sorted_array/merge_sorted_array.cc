// Source: https://leetcode-cn.com/problems/merge-sorted-array
// Author: Shihao Liu
// Date: 2021-12-02

#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 插入排序
  *
  * 时间复杂度: O(m*n + n^2)
  *
  * 最坏情况: nums2中所有元素小于nums1中的所有元素, 则第i次插入需要交换m+i次, 总共执行
  * n次插入, 耗时O(m*n + n^2). m远大于n时, 复杂度近似为O(m*n); m远小于n时, 复杂度近似
  * 于O(n^2).
  */
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int tmp;
    for (int i = 0; i < n; i++) {
      nums1[m + i] = nums2[i]; // 先将元素(记作z)添加到nums1的末端
      // 若z小于其左侧相邻元素, 则将两个交换位置; 重复这个过程直到z不小于其左侧相邻元素
      for (int j = m + i; j > 0 && nums1[j - 1] > nums1[j]; j--) {
        tmp = nums1[j - 1];
        nums1[j - 1] = nums1[j];
        nums1[j] = tmp;
      }
    }
  }

};

class Solution_2 {
 public:
  /**
  * @brief 链表, STL
  *
  * 时间复杂度: O(m+n)
  *
  * 可直接使用STL中的list容器及其merge()方法.
  * 借助copy()函数将合并后的列表元素写回到nums1中
  */
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    list<int> l1(nums1.begin(), nums1.begin() + m);
    list<int> l2(nums2.begin(), nums2.end());
    l1.merge(l2);
    copy(l1.begin(), l1.end(), nums1.begin());
  }

};

class Solution_3 {
 public:
  /**
  * @brief 双指针
  *
  * 时间复杂度: O(m+n)
  *
  * 在nums1的末端维护一个局部有序序列, 该序列的下一个插入位置由k维护. 双指针所指处的元素
  * 的较大者被插入到该局部序列中. 每轮循环结束, 该局部序列的有序性都得到保证.
  * 至多执行m+n次比较.
  */
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int k = m + n - 1;
    m--;
    n--;
    while (m >= 0 && n >= 0) {
      nums1[k--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    while (n >= 0) {
      nums1[k--] = nums2[n--];
    }

  }

};
