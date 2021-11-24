// Source: https://leetcode-cn.com/problems/implement-strstr
// Author: Shihao Liu
// Date: 2021-11-21

#include <iostream>
#include <string>
#include <vector>

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


// AC
class Solution_2 {
 private:
  // 初始化: 依据模式串t生成next数组
  // 要求: 模式串不为空
  void kmp_init(const string& t, vector<int>& next) {
    next[0] = -1; // 规定
    int i = 0, j = -1;
    int m = t.size();
    while (i < m - 1) {
      if (j == -1 || t[i] == t[j]) {
        i++;
        j++;
        next[i] = j;
      } else {
        j = next[j];
      }
    }
  }

 public:
  /**
  * @brief KMP算法(背诵)
  *
  * 时间复杂度: O(n+m), n, m分别为主串和模式串的长度.
  *
  * KMP代码实现太难了, 搞了一整晚思路还是理不清.
  * 把它当模板背下来吧...
  * (注意: 数组下标从0开始)
  */
  int strStr(string haystack, string needle) {
    // 先处理模式串为空的情况
    if (needle.empty()) {
      return 0;
    }
    int n = haystack.size(), m = needle.size();
    vector<int> next(m);
    kmp_init(needle, next);
    int i = 0, j = 0;
    while(i < n && j < m) {
      if (j == -1 || haystack[i] == needle[j]) {
        i++;
        j++;
      } else {
        j = next[j];
      }
    }
    if (j == m) {
      return i - m;
    } else {
      return -1;
    }
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

  Solution_2 sol2;
  h = "ababcababa"; n = "ababa";
  cout << sol2.strStr(h, n) << endl;;
}