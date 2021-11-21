// Source: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
// Author: Shihao Liu
// Date: 2021-11-21

#include <vector>

using namespace std;

// AC
class Solution_1 {
 public:
  /**
  * @brief 双索引: 一个快一个慢
  *
  * 时间复杂度: O(n)
  * 空间复杂度: O(1)
  *
  * 维护两个索引i和k.
  * 索引i遍历原数组, 索引k指示新数组中的下一个元素的保存位置
  */
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) {
      return nums.size();
    }
    int i, k = 1;
    for (i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1]) { // nums[i]不是重复元素
        nums[k] = nums[i];
        k++;
      } // 当nums[i]是重复元素时, 不做任何处理.
    }
    return k;
  }

};