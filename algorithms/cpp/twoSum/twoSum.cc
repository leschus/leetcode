// Source: https://leetcode-cn.com/problems/twoSum
// Author: Shihao Liu
// Date: 2021-11-18

#include <vector>
#include <unordered_map>

using namespace std;

// AC
class Solution_1 {
 public:
  /**
  * @brief 暴力求解法: 两层循环
  *
  * 时间复杂度: O(n^2)
  */
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          result.push_back(i);
          result.push_back(j);
        }
      }
    }
    return result;
  }
};

// AC
class Solution_2 {
 public:
  /**
  * @brief 使用哈希表, 数组元素值作为键, 下标作为值
  *
  * 时间复杂度: O(n)
  *
  * 通过一层循环, 检查target - nums[i]是否在map中, 若不在, 将nums[i]添加到map;
  * 若在, 则说明存在一组下标i和map[target-nums[i]], 它们指定位置处的两数之和等于
  * target.
  */
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) {
      if (umap.find(target - nums[i]) == umap.end()) {
        umap[nums[i]] = i;
      } else {
        result.push_back(i);
        result.push_back(umap[target - nums[i]]);
        break;
      }
    }
    return result;
  }

};

// AC
class Solution_3 {
 public:
  /**
  * @brief 使用哈希表, 数组元素值作为键, 下标作为值
  *
  * 时间复杂度: O(n)
  *
  * 本方案与方案2的不同之处在于, 循环过程中, 往map中添加的是target-nums[i]而不是nums[i],
  * 从而map中的键值反映的关系发生了变化. map[key] == value, 表示nums中如果存在一个值为
  * key的元素, 那么该元素和下标value处的元素之和就一定等于target.
  * 然而, 方案3和方案2的时间复杂度都是O(n).
  */
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) {
      if (umap.find(nums[i]) == umap.end()) {
        umap[target - nums[i]] = i;
      } else {
        result.push_back(i);
        result.push_back(umap[nums[i]]);
        break;
      }
    }
    return result;
  }

};