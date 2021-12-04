// 随机抽样 (蓄水池算法)

// 问题描述:
//    从N个数中随机抽取M (M<=N) 个数, 要求每个数被抽取到的概率都相同 (即M/N).

#include <cstdlib>
// #include <ctime>
#include <vector>
using namespace std;


class Solution_1 {
 public:
  /**
  * @brief 随机抽样 (蓄水池算法)
  *
  * @时间复杂度 O(n)
  *
  * 整个过程只需要遍历一遍nums数组
  */
  vector<int> RandomSelect(vector<int> nums, int m) {
    int n = nums.size();
    vector<int> ans(nums.begin(), nums.begin() + m);
    for (int i = m; i < n; i++) {
      int j = rand() % i; // 生成[0, i - 1]中的一个随机整数j
      if (j < m) { // 如果j属于区间[0, m - 1]. (发生概率为: m/i)
        ans[j] = nums[i];
      }
    }
    return ans;
  }

};