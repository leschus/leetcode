// Source: https://leetcode-cn.com/problems/pascals-triangle-ii
// Author: Shihao Liu
// Date: 2021-12-10

#include <vector>
using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 使用和118.pascals_triangle一样的方法
  *
  * @时间复杂度 O(n^2)
  *
  * 本算法实际上求出了第0行至第rowIndex行的每一行的内容, 但结果只返回第rowIndex行.
  */
  vector<int> getRow(int rowIndex) {
    vector<vector<int>> ans(rowIndex + 1);
    for (int i = 0; i <= rowIndex; i++) {
      ans[i].resize(i + 1);
      ans[i][0] = ans[i][i] = 1;
      for (int j = 1; j < i; j++) {
        ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
      }
    }
    return ans[rowIndex];
  }
};

class Solution_2 {
 public:
  /**
  * @brief 对解法1的优化: 使用滚动数组
  *
  * @时间复杂度 O(n^2)
  */
  vector<int> getRow(int rowIndex) {
    vector<int> pre, cur;
    for (int i = 0; i <= rowIndex; i++) {
      cur.resize(i + 1);
      cur[0] = cur[i] = 1;
      for (int j = 1; j < i; j++) {
        cur[j] = pre[j - 1] + pre[j];
      }
      pre = cur;
    }
    return cur;
  }

};

class Solution_3 {
 public:
  /**
  * @brief 线性递推
  *
  * @时间复杂度 O(n)
  *
  * 利用C(n, m) = n! / ((m!) * (n - m)!), 得到C(n, m)和C(n, m-1)的关系:
  * C(n, m) = C(n, m-1) * (n - m + 1) / m;
  * 已知C(n, 0) = 1, 可根据上面递推式依次求出C(n, i), i = 1, 2, ..., n
  */
  vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex + 1);
    ans[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
      ans[i] = 1LL * ans[i - 1] * (rowIndex - i + 1) / i;
    }
    return ans;
  }

};