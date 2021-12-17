// Source: https://leetcode-cn.com/problems/single-number
// Author: Shihao Liu
// Date: 2021-12-17

#include <algorithm>
#include <vector>
using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 先排序再处理
  *
  * @时间复杂度 O(nlogn), 用到了排序
  */
  int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i;
    for (i = 0; i + 1 < nums.size(); i += 2) {
      if (nums[i] != nums[i + 1]) {
        return nums[i];
      }
    }
    if (i < nums.size()) {
      return nums[i];
    }
    return 0; // 对于合法输入, 不会执行到这一步
  }
};

class Solution_2 {
 public:
  /**
  * @brief 异或运算
  *
  * @时间复杂度 O(n)
  * @空间复杂度 O(1)
  *
  * 假设总共2m+1个数, a(1), a(2), ..., a(m)为出现了两次的数; a(2m+1)为只出现了
  * 一次的那个数. 由于异或运算满足以下性质:
  *   - 任意整数异或0, 得其自身;
  *   - 任意整数与其自身进行异或, 得0;
  *   - 异或运算满足交换律和结合律;
  * 因此, 这2m+1个数的连续异或总可以写成:
  *   (a(1)^a(1)) ^ (a(2)^a(2)) ^ ... ^ (a(m)^a(m)) ^ a(2m+1)
  * 等价于:
  *   0 ^ 0 ^ ... ^ 0 ^ a(2m+1)
  * 所以最终结果等于:
  *   a(2m+1)
  *
  * 从而得出结论, 2m+1个数中仅出现了1次的那个数的值就等于将所有数进行异或运算后得到的结果的值
  */
  int singleNumber(vector<int>& nums) {
    int ret = 0;
    for (int &x: nums) {
      ret ^= x;
    }
    return ret;
  }

};