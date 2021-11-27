// Source: https://leetcode-cn.com/problems/length-of-last-word
// Author: Shihao Liu
// Date: 2021-11-25


#include <string>
// #include <cassert>

using namespace std;

// AC
class Solution_1 {
 public:
  /**
  * @brief 逆序遍历
  *
  * 时间复杂度: O(n)
  *
  * 题目前提: s中至少有一个单词, s中只有字母和空格字符.
  *
  * 逆向遍历字符串, 从第一个非空白字符开始计数, 直到遇到空白字符或者到达字符串
  * 左端.
  */
  int lengthOfLastWord(string s) {
    int count = 0, i = s.size() - 1;
    while (s[i] == ' ') {   // i定位到s中最后一个非空格字符
      i--;
    }
    while (i >= 0 && s[i] != ' ') {
      count++;
      i--;
    }
    return count;
  }

};