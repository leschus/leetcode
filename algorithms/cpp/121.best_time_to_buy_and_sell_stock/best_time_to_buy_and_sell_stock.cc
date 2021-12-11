// Source: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
// Author: Shihao Liu
// Date: 2021-12-11

#include <iostream>
#include <vector>
using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 动态规划, (参见053.maximum_subarray)
  *
  * @时间复杂度 O(n)
  * @空间复杂度 O(1)
  *
  * 本解法不需要事先计算出一个完整的changes数组, 只需要一个change变量. 因为观察到循环体内
  * 其实每轮只用到了prices[i] - prices[i - 1]的值.
  */
  int maxProfit(vector<int>& prices) {
    int change;
    int max = 0, pre = 0;
    for (int i = 1; i < prices.size(); i++) {
      change = prices[i] - prices[i - 1];
      if (change + pre >= change) {
        pre += change;
      } else {
        pre = change;
      }
      if (max < pre) {
        max = pre;
      }
    }
    return max;
  }

};

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  Solution_1 sol1;
  cout << sol1.maxProfit(prices) << endl;
}