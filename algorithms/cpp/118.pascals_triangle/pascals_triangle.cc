// Source: https://leetcode-cn.com/problems/pascals-triangle
// Author: Shihao Liu
// Date: 2021-12-08

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 数学
  *
  * @时间复杂度 O(n^2)
  *
  * 每一个新行都是从空开始逐个插入元素
  * vector的自动扩容会消耗部分时间
  */
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    vector<int> last_row, current_row;
    while (numRows--) {
      if (last_row.size() < 2) {
        current_row.push_back(1);
        last_row =current_row;
      } else {
        current_row.clear();
        int len = last_row.size();
        vector<int>::iterator it = last_row.begin();
        current_row.push_back(1);
        while (--len) {
          current_row.push_back(*it + *(++it));
        }
        current_row.push_back(1);
        last_row = current_row;
      }
      ans.push_back(current_row);
    }
    return ans;
  }

};

class Solution_2 {
 public:
  /**
  * @brief 数学
  *
  * @时间复杂度 O(n^2)
  *
  * 事先为vector一次性分配好空间, 避免在插入时再去扩容.
  */
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows); // 分配n行, 每行为空
    for (int i = 0; i < numRows; i++) {
      ans[i].resize(i + 1); // 第i行包含i + 1个数
      ans[i][0] = ans[i][i] = 1; // 每行的第一个和最后一个数总为1
      // 利用上一行中的对应元素之和初始化本行中的对应元素
      for (int j = 1; j < i; j++) {
        ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
      }
    }
    return ans;
  }

};

int main() {
  Solution_2 sol2;
  auto ans = sol2.generate(5);
  for (auto row: ans) {
    for (auto e: row) {
      cout << e << " ";
    }
    cout << endl;
  }

}