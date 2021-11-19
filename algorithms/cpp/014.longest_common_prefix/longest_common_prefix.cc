// Source: https://leetcode-cn.com/problems/longest-common-prefix
// Author: Shihao Liu
// Date: 2021-11-19

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// AC
class Solution_1 {
 public:
  /**
  * @brief 纵向扫描. 选定基准字符串, 并于其它字符串逐字符比较
  *
  * 时间复杂度: O(n*m), n为strs长度, m为strs中字符串的平均长度
  *
  * 以第一个字符串为基准, 使用i遍历基准字符串的每个下标, 依次比较其它字符串中的第i个字符
  * 是否和基准字符串的第i个字符相等, 若都相同, 则将基准字符串的第i个字符加入到结果中.
  *
  * 最坏情况下, 算法外层循环m次, m为基准字符串长度; 内层循环n次, n为strs包含的字符串个数.
  * 故共时间复杂度为O(m*n).
  */
  string longestCommonPrefix(vector<string>& strs) {
    // 这个判断不加也可以AC, 但加了更严谨, 因为算法主体默认strs中至少有一个字符串
    if (!strs.size())
      return "";
    string result;
    char c;
    for (int i = 0; i < strs[0].size(); i++) {
      c = strs[0][i];
      bool flag = true;
      for (int j = 1; j < strs.size(); j++) {
        if (strs[j][i] != c) {
          flag = false;
          break;
        }
      }
      if (flag) {
        result += c;
      } else {
        break;
      }
    }
    return result;
  }

};

int main() {
  vector<string> strs1 = {"", "abc"};
  vector<string> strs2 = {"aabbc", "aabcc", "aabxyz"};
  Solution_1 sol;
  cout << sol.longestCommonPrefix(strs1) << endl;
  cout << sol.longestCommonPrefix(strs2) << endl;

}