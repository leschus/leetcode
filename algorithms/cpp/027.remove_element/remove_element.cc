// Source: https://leetcode-cn.com/problems/remove-element
// Author: Shihao Liu
// Date: 2021-11-21

#include <vector>
using namespace std;

// AC
class Solution_1 {
 public:
  /**
  * @brief 双指针
  *
  * 时间复杂度: O(n)
  * 空间复杂度: O(1)
  *
  * 索引i遍历数组, 索引k指示新数组中下一个元素的存放位置
  *
  * 最坏情况下, 数组中没有元素等于val, 则索引i和k均要遍历数组一遍.
  *
  */
  int removeElement(vector<int>& nums, int val) {
    int i, k = 0;
    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != val) { // 如果当前元素不等于val, 则将其移到新位置
        nums[k] = nums[i];
        k++;
      } // 如果当前元素等于val, 则什么也不做
    }
    return k;
  }

};

// AC
class Solution_2 {
 public:
  /**
  * @brief 双指针(优化)
  *
  * 时间复杂度: O(n)
  * 空间复杂度: O(1)
  *
  * 本优化方案利用了题目条件: 允许改变元素顺序.
  *
  * 使用左右指针, 初始时分别指向数组的第一个元素和超尾元素.
  * 当左指针元素等于val时, 用右指针元素覆盖左指针元素, 同时右指针左移一位;
  * 若此时的左指针元素仍为val, 则继续上述操作, 直到左指针元素不等于val, 此时将左指针
  * 右移一位.
  * 循环结束条件: 左指针与右指针重合(left >= right)
  *
  * 在数组中等于val的元素偏少时, 本解法执行的移动操作少于解法1. 例如nums=
  * [1,2,3,4,5], val=1时, 本解法只需移动一次元素(将元素5移至元素1的位置), 而解法1
  * 需要移动4次.
  *
  * 此外, 本解法的左右指针总是合起来遍历一遍数组; 而解法1的索引i和k则是至少遍历一遍
  * 数组最坏情况下遍历了两遍数组.
  */
  int removeElement(vector<int>& nums, int val) {
    int left = 0, right = nums.size();
    while (left < right) {
      if (nums[left] == val) {
        nums[left] = nums[right - 1];
        right--;
      } else {
        left++;
      }
    }
    return left;
  }

};