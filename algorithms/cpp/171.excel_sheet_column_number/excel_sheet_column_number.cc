// Source: https://leetcode-cn.com/problems/excel-sheet-column-number
// Author: Shihao Liu
// Date: 2022-01-06

#include <bits/stdc++.h>
using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 数学
  *
  * @时间复杂度 O(n)
  */
  int titleToNumber(string columnTitle) {
    size_t n = columnTitle.size(), i = 0;
    int res = 0;
    while (i < n) {
      res = res * 26 - 'A' + columnTitle[i] + 1; // 先减再加，否则最后一个测试用例会算数溢出
      ++i;
    }
    return res;
  }
};