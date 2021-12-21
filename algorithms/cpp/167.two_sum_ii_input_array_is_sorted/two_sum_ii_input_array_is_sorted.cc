// Source: https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
// Author: Shihao Liu
// Date: 2021-12-21

#include <vector>
using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 两层循环(需要剪枝, 否则超时)
  *
  * @时间复杂度 O(n^2)
  */
  vector<int> twoSum(vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size(); ++i) {
      if (i && numbers[i] == numbers[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < numbers.size(); ++j) {
        if (numbers[i] + numbers[j] == target) {
          return vector<int> {i + 1, j + 1};
        }
      }
    }
    return vector<int>(0, 0);
  }

};

class Solution_2 {
 public:
  /**
  * @brief 双指针
  *
  * @时间复杂度 O(n)
  */
  vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1, tmp;
    while (i < j) {
      tmp = numbers[i] + numbers[j];
      if (tmp == target) {
        return vector<int> {i + 1, j + 1};
      } else if (tmp < target) {
        ++i;
      } else {
        --j;
      }
    }
    return vector<int> (0, 0);
  }

};