// Source: https://leetcode-cn.com/problems/climbing-stairs
// Author: Shihao Liu
// Date: 2021-11-29

#include <iostream>
using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 递归
  *
  * 时间复杂度: O(2^n)
  *
  * 递推式: f(n) = f(n-1) + f(n-2), f(1) = 1, f(2) = 2;
  *
  * 这种直截了当的递归造成了大量的重复计算, 导致算法效率低下
  */
  int climbStairs(int n) {
    // cout << "n = " << n << endl;
    if (n == 1 || n == 2) {
      return n;
    }
    return climbStairs(n-1) + climbStairs(n-2);
  }

};

class Solution_2 {
 public:
  /**
  * @brief 动态规划 (迭代)
  *
  * 时间复杂度: O(n)
  *
  * 同样是利用递推式, 但是不用递归, 而是自底向上地通过迭代的方式求出f(n)
  *
  * 由于避免了自顶向下计算时出现的大量重复求解, 本算法效率提升至O(n)
  */
  int climbStairs(int n) {
    if (n == 1 || n == 2) {
      return n;
    }
    int a = 1, b = 2, x = 3;
    while (x <= n) {
      b = a + b;
      a = b - a;
      x++;
    }
    return b;
  }

};

int main() {
  Solution_1 sol1;
  cout << sol1.climbStairs(10) << endl;
  Solution_2 sol2;
  cout << sol2.climbStairs(10) << endl;

}