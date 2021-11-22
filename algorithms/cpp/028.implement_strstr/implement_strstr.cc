// Source: https://leetcode-cn.com/problems/implement-strstr
// Author: Shihao Liu
// Date: 2021-11-21

#include <iostream>
#include <string>

using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 暴力求解
  *
  * 时间复杂度: O(m*n)
  *
  * 从haystack中找出needle出现的第一个位置. 不存在时返回-1. needle为空串时返回0.
  *
  * tip: 如果不事先保存两个串的长度到变量中, 而是在for循环判断里临时调用size(), 则
  * 提交答案后, 最后一个测试用例将会"超出时间限制".
  */
  int strStr(string haystack, string needle) {
    if (needle == "") {
      return 0;
    }
    int len1 = haystack.size(), len2 = needle.size();
    int i, j;
    for (i = 0; i + len2 <= len1; i++) {
      for (j = 0; j < len2; j++) {
        if (haystack[i + j] == needle[j]) {
          continue;
        } else {
          break;
        }
      }
      if (j == len2) {
        return i;
      }
    }
    return -1;
  }

};

int main() {
  string h = "hello", n = "ll";
  Solution_1 sol;
  cout << sol.strStr(h, n) << endl;
  h = "aaaaa"; n = "bba";
  cout << sol.strStr(h, n) << endl;
  h = ""; n = "";
  cout << sol.strStr(h, n) << endl;
}