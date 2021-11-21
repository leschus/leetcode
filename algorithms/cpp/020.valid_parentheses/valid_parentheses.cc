// Source: https://leetcode-cn.com/problems/valid-parentheses
// Author: Shihao Liu
// Date: 2021-11-21

#include <string>
#include <stack>
#include <unordered_map>

using namespace std;


// AC
class Solution_1 {
 private:
  unordered_map<char, char> m = {
    {'(', ')'},
    {'{', '}'},
    {'[', ']'}
  };
 public:
  /**
  * @brief 使用栈进行括号匹配
  *
  * 时间复杂度: O(n)
  *
  * 按序从s中取出字符s[i]:
  *   1. 如果是左括号, 则直接入栈;
  *   2. 如果是右括号:
  *     a. 若栈顶是和s[i]相匹配的左括号, 则弹出栈顶元素; (前提是栈非空)
  *     b. 否则, 可提前确认s不合法, break.
  * 循环结束, 若栈空, 则说明括号序列合法;
  * trick: 借助哈希表来检验括号是否配对, 可减少代码量.
  */
  bool isValid(string s) {
    stack<char> sc;
    int i;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        sc.push(s[i]);
      } else {
        // 这里要预先判断栈非空
        if (!sc.empty() && m[sc.top()] == s[i]) {
          sc.pop();
        } else {
          // 这里先压栈再返回是为了使得栈空的情况下碰到一个右括号导致提前结束
          // 循环时, 仍能通过栈非空来确认序列非法
          sc.push(s[i]);
          break;
        }
      }
    }
    return sc.empty();
  }

};