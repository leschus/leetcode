// Source: https://leetcode-cn.com/problems/search-insert-position
// Author: Shihao Liu
// Date: 2021-11-23

#include <vector>
#include <iostream>

using namespace std;

// AC
class Solution_1 {
 public:
  /**
  * @brief 暴力求解, 正向遍历
  *
  * 时间复杂度: O(n)
  *
  */
  int searchInsert(vector<int> nums, int target) {
    int i;
    for (i = 0; i < nums.size(); i++) {
      if (nums[i] >= target) {
        break;
      }
    }
    return i;
  }

};

// AC
class Solution_2 {
 private:
  int binarySearch(const vector<int>& nums, int left, int right, int target) {
    if (left > right) { // nums中没有元素等于target
      return left;
    }
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      return binarySearch(nums, left, mid - 1, target);
    } else {
      return binarySearch(nums, mid + 1, right, target);
    }
  }

 public:
  /**
  * @brief 二分查找(递归版本)
  *
  * 时间复杂度: O(logn)
  */
  int searchInsert(vector<int> nums, int target) {
    return binarySearch(nums, 0, nums.size() - 1, target);
  }

};

// AC
class Solution_3 {
 public:
  /**
  * @brief 二分查找(迭代版本)
  *
  * 时间复杂度: O(logn)
  */
  int searchInsert(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) { // 从左半边继续查找
        right = mid - 1;
      } else {  // 从右半边继续查找
        left = mid + 1;
      }
    }
    return left;
  }

};

int main() {
  vector<int> nums {1, 3, 5, 6};
  Solution_2 sol2;
  cout << sol2.searchInsert(nums, 3) << endl;
  cout << sol2.searchInsert(nums, 7) << endl;
  cout << sol2.searchInsert(nums, 2) << endl;

  Solution_3 sol3;
  cout << sol3.searchInsert(nums, 3) << endl;
  cout << sol3.searchInsert(nums, 7) << endl;
  cout << sol3.searchInsert(nums, 2) << endl;
}