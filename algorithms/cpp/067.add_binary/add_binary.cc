// Source: https://leetcode-cn.com/problems/add-binary
// Author: Shihao Liu
// Date: 2021-11-27

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

/*

Constraints:
  1) 1 <= a.length, b.length <= 10^4
  2) a and b consist only of '0' or '1' characters.
  3) Each string does not contain leading zeros except for the zero itself.
*/

class Solution_1 {
 public:
  /**
  * @brief 模拟竖式加法
  *
  * 时间复杂度: O(n), n为字符串a和b的长度的较大者
  *
  * 低位对齐, 从低位向高位依次执行按位加法, 维护一个进位carry
  */
  string addBinary(string a, string b) {
    string &s = a.size() >= b.size() ? a : b;
    string &t = a.size() >= b.size() ? b : a;
    int i = s.size() - 1, j = t.size() - 1;
    string ans;
    assert(i >= j);
    int carry = 0;
    while (i >= 0) {
      carry += s[i] == '1';
      carry += j >= 0 ? (t[j] == '1') : 0;
      ans.push_back((carry % 2) ? '1' : '0');
      i--;
      j--;
      carry /= 2;
    }
    if (carry) {
      ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());  // 生成的ans中数字是倒的, 需要翻转一下
    return ans;
  }

};

int main() {
  string a = "1010101", b = "11101";
  Solution_1 sol1;
  cout << sol1.addBinary(a, b) << endl;
}