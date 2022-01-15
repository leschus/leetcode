// Source: https://leetcode-cn.com/problems/number-of-1-bits
// Author: Shihao Liu
// Date: 2022-01-15

#include <bits/stdc++.h>

class Solution_1 {
 public:
  /**
  * @brief 位运算
  *
  * @时间复杂度 O(log32)
  */
  int hammingWeight(uint32_t n) {
      int x = 0;
      while (n) {
          if (n & 1) {
              ++x;
          }
          n >>= 1;
      }
      return x;
  }

};