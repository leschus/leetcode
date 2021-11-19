// Source: https://leetcode-cn.com/problems/palindrome-number
// Author: Shihao Liu
// Date: 2021-11-19

#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

// AC
class Solution_1 {
 public:
  /**
  * @brief 将整数转换成字符串再做处理
  *
  * 时间复杂度: O(log|x|)
  */
  bool isPalindrome(int x) {
    string s = to_string(x);
    string t;
    reverse_copy(s.begin(), s.end(), insert_iterator<string>(t, t.begin()));
    return s == t;
  }

};

// AC
class Solution_2 {
 public:
  /**
  * @brief 使用模10和除10操作来翻转一个末位非0的正整数
  *
  * 时间复杂度: O(log|x|)
  */
  bool isPalindrome(int x) {
    if (x == 0)
      return true;
    if (x < 0 || !(x % 10)) // 如果x为负, 或x的末位为0
      return false;
    int m = x, digit;
    long n = 0;             // 将x反转后的值可能超出INT_MAX, 因此要用long保存
    while (m != 0) {
      digit = m % 10;
      m /= 10;
      n = n * 10 + digit;
    } // 循环结束后, n将成为m的反转
    return x == n;
  }

};