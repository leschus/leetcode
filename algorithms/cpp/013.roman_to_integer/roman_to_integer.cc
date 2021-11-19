// Source: https://leetcode-cn.com/problems/roman-to-integer
// Author: Shihao Liu
// Date: 2021-11-19

#include <string>
#include <unordered_map>

using namespace std;

// AC
class Solution_1 {
 public:
  /**
  * @brief 一大串if-else条件判断...又臭又长 :(
  *
  * 时间复杂度: O(s.length())
  */
  int romanToInt(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
      switch (s[i]) {
      case 'I':
        if ((i + 1) < s.size()) {
          if (s[i + 1] == 'V') {
            result += 4;
            i++;
          } else if (s[i + 1] == 'X') {
            result += 9;
            i++;
          } else {
            result += 1;
          }
        } else {
          result += 1;
        }
        break;
      case 'V':
        result += 5;
        break;
      case 'X':
        if ((i + 1) < s.size()) {
          if (s[i + 1] == 'L') {
            result += 40;
            i++;
          } else if (s[i + 1] == 'C') {
            result += 90;
            i++;
          } else {
            result += 10;
          }
        } else {
          result += 10;
        }
        break;
      case 'L':
        result += 50;
        break;
      case 'C':
        if ((i + 1) < s.size()) {
          if (s[i + 1] == 'D') {
            result += 400;
            i++;
          } else if (s[i + 1] == 'M') {
            result += 900;
            i++;
          } else {
            result += 100;
          }
        } else {
          result += 100;
        }
        break;
      case 'D':
        result += 500;
        break;
      case 'M':
        result += 1000;
        break;
      }
    }
    return result;
  }

};

// AC
class Solution_2 {
 private:
  unordered_map<char, int> symbol_value {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000}
  };

 public:
  /**
  * @brief 使用哈希表建立映射关系
  *
  * 时间复杂度: O(s.length())
  *
  * 如果s中的罗马数字字符是按数值非升序给出的, 则只需将这些字符对应的数值依次相加即可得到该
  * 罗马数字所表示的整数值. 如CXVI表示100+10+5+1等于116;
  * 如果s中的罗马数字字符并非遵照非升序排列, 即存在相邻的两个字符, 数值小的字符在数值大的字符
  * 的左边, 如IX, 依据规则, 这两个相邻字符表示的数值等于右侧字符的数值减去左侧字符数值. 这种
  * 情况下也可以看成是将左侧字符的数值取反, 再与相邻字符数值相加.
  *
  * 根据以上分析, 只需遍历一遍数字字符, 默认执行数值累加操作, 仅当当出现相邻的两个字符, 左边
  * 字符数值小于右边字符数值时, 将左边字符数值取反再相加即可.
  */
  int romanToInt(string s) {
    int result = 0;
    int length = s.size();
    for (int i = 0; i < length; i++) {
      int value = symbol_value[s[i]];
      if (i < length - 1 && value < symbol_value[s[i + 1]]) {
        result -= value;
      } else {
        result += value;
      }
    }
    return result;
  }

};