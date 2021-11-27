// Source: https://leetcode-cn.com/problems/maximum-subarray
// Author: Shihao Liu
// Date: 2021-11-24

#include <climits>
#include <vector>
#include <iostream>
using namespace std;

// 超出时间限制
class Solution_1 {
 public:
  /**
  * @brief 暴力求解
  *
  * 时间复杂度: O(n^2)
  */
  int maxSubArray(vector<int>& nums) {
    int max = INT_MIN, tmp;
    for (int i = 0; i < nums.size(); i++) {
      tmp = 0;
      for (int j = i; j < nums.size(); j++) {
        tmp += nums[j];
        if (tmp > max) {
          max = tmp;
        }
      }
    }
    return max;
  }

};

// AC
class Solution_2 {
 private:
  int maxSub(vector<int> &nums, int left, int right) {
    if (left == right) {
      return nums[left];
    }
    int mid = (left + right) / 2;
    int lmax = maxSub(nums, left, mid);
    int rmax = maxSub(nums, mid + 1, right);
    int cross_lmax = nums[mid], cross_rmax = nums[mid + 1], cross_max;
    int tmp = nums[mid], i;
    for (i = mid - 1; i >= left; i--) {
      tmp += nums[i];
      if (tmp > cross_lmax) {
        cross_lmax = tmp;
      }
    }
    tmp = nums[mid + 1];
    for (i = mid + 2; i <= right; i++) {
      tmp += nums[i];
      if (tmp > cross_rmax) {
        cross_rmax = tmp;
      }
    }
    cross_max = cross_lmax + cross_rmax;
    // 比较得到三种情形下的最大值
    if (lmax > rmax) {
      if (lmax > cross_max) {
        return lmax;
      } else {
        return cross_max;
      }
    } else {
      if (rmax > cross_max) {
        return rmax;
      } else {
        return cross_max;
      }
    }
  }
 public:
  /**
  * @brief 分治法, 递归(参考算法导论4.1)
  *
  * 时间复杂度: O(nlogn)
  *
  * 分治策略: 取数组A[low...high]的中间位置mid. 最大子数组可能存在于:
  *   * 左半数组A[low, mid]中;
  *   * 右半数组A[mid+1, high]中;
  *   * 跨越了mid元素的子数组A[i...j]中, 其中low <= i <= mid < j <= high;
  *
  * 算法导论上的策略可以用来输出最大子数组的具体位置不仅仅是其最大和, 用在这个
  * 题目上有点大材小用了, 所以虽然AC, 但并不理想.
  */
  int maxSubArray(vector<int>& nums) {
    return maxSub(nums, 0, nums.size() - 1);
  }

};

class Solution_3 {
 public:
  /**
  * @brief 动态规划
  *
  * 时间复杂度:
  *
  * 记f(i)为以i结尾的最大子序列和, 则:
  *     f(i) = max{f(i-1) + nums[i], nums[i]}
  * 遍历一遍数组即可求得每一个f(i), 这里不需要用数组保存每一个f(i), 根据公式,
  * 只需要再进行第i轮时用到上一轮求得的f(i)即可
  * 数组f中的最大值即为所求.
  *
  */
  int maxSubArray(vector<int>& nums) {
    int max, pre;
    max = pre = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (pre + nums[i] >= nums[i]) {
        pre += nums[i];
      } else {
        pre = nums[i];
      }
      if (pre > max) {
        max = pre;
      }
    }
    return max;
  }

};


int main() {
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  Solution_1 sol1;
  cout << sol1.maxSubArray(nums) << endl;
  Solution_2 sol2;
  cout << sol2.maxSubArray(nums) << endl;

  Solution_3 sol3;
  cout << sol3.maxSubArray(nums) << endl;
}