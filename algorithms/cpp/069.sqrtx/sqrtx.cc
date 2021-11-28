// Source: https://leetcode-cn.com/problems/sqrtx
// Author: Shihao Liu
// Date: 2021-11-28

#include <cmath>
using namespace std;

class Solution_1 {
 public:
  /**
  * @brief mini-calculator
  *
  * 时间复杂度: O(1), assumes that both exp() and log() are O(1)
  *
  * using exp() and log()
  */
  int mySqrt(int x) {
    if (x == 0) {
      return 0;
    }
    int ans = exp(0.5 * log(x));
    // floats are not accurate, need to check whether ans or ans + 1 is the
    // right answer.
    return (long long) (ans + 1) * (ans + 1) <= x ? (ans + 1) : ans;
  }

};

class Solution_2 {
 public:
  /**
  * @brief Binary Search
  *
  * 时间复杂度: O(logn)
  */
  int mySqrt(int x) {
    int l = 0, r = x, mid, ans = -1;
    while (l <= r) {
      // mid = (l + r) / 2;
      mid = l + (r - l) / 2;  // to avoid that l + r exceeds the INT_MAX
      if ((long long)mid * mid <= x) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  }

};

class Solution_3 {
 public:
  /**
  * @brief Newton's Method
  *
  * 时间复杂度: O(logn)
  */
  int mySqrt(int x) {
    if (x == 0) {
      return 0;
    }
    double C = x, x0 = x;
    while (true) {
      double xi = 0.5 * (x0 + C / x0);
      if (fabs(x0 - xi) <= 1e-6) {
        break;
      }
      x0 = xi;
    }
    return (int)x0;
  }

};