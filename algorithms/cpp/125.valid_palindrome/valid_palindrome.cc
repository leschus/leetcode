// Source: https://leetcode-cn.com/problems/valid-palindrome
// Author: Shihao Liu
// Date: 2021-12-15

#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 字符串操作
  *
  * @时间复杂度 O(n)
  *
  * 只考虑字母和和数字字符, 忽略大小写
  */
  bool isPalindrome(string s) {
    auto new_end = remove_if(s.begin(), s.end(), [](char c) {
      return !isalnum(c);
      });
    s.erase(new_end, s.end());
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (tolower(s[i]) != tolower(s[j])) {
        return false;
      }
      i++; j--;
    }
    return true;
  }

};


class Solution_2 {
 public:
  /**
  * @brief 字符串操作, 优化
  *
  * @时间复杂度 O(n)
  *
  * 在remove_if中同时执行tolower转换
  */
  bool isPalindrome(string s) {
    auto new_end = remove_if(s.begin(), s.end(), [](char& c) {
      if (isalnum(c)) {
        c = tolower(c);
        return false;
      }
      return true;
    });
    s.erase(new_end, s.end());
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++; j--;
    }
    return true;
  }

};

int main() {
  string s = "A man, a plan, a canal: Panama";
  auto new_end = remove_if(s.begin(), s.end(), [](char &c) {
    if (isalnum(c)) {
      c = tolower(c);
      return false;
    }
    return true;
  });
  s.erase(new_end, s.end());
  cout << s << endl;
}