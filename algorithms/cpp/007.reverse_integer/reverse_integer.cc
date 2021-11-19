// Source: https://leetcode-cn.com/problems/reverse-integer
// Author: Shihao Liu
// Date: 2021-11-18

#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

// Wrong
class Solution_1 {
 public:
  /**
  * @brief TODO
  *
  * 时间复杂度: O(1)
  *
  * 将int转换成字符数组并使用字符串处理函数来协助操作.
  * 为确认反转后的结果是否超出32为符号整数的表示范围, 将INT_MAX和INT_MIN也相应地转换成
  * 字符数组表示, 并借助strcmp()来判断是否超限.
  * 注意: 对于32位有符号整数, 其最大值为2147483647, 最小值为-2147483648, 要为数组分配
  * 足够的空间以保存这么多位的数字.
  * 因为数组长度为常数值, 因此算法的时间复杂度为O(1).
  */
  int reverse(int x) {
    bool flag = x < 0;  // 正负标记
    if (flag) x = -x;   // 取绝对值
    char s[20], int_max[20], int_min[20];
    itoa(x, s, 10);
    itoa(INT_MAX, int_max, 10);
    itoa(INT_MIN, int_min, 10);
    char tmp;
    int i, j = strlen(s) - 1;
    while (j > 0 && s[j] == '0') { // 去掉s尾部的'0'. 如果s中全为'0', 则保留最后一个.
      s[j] = '\0';
      j--;
    }
    for (i = 0; i < j; i++, j--) { // 反转s
      tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;
    }
    if (!flag) {
      if (strcmp(s, int_max) <= 0) {
        return atoi(s);
      } else {
        return 0;
      }
    } else {
      if (strcmp(s, int_min + 1) <= 0) {
        return -atoi(s);
      } else {
        return 0;
      }
    }
  }

};

// Wrong
class Solution_2 {
 public:
  /**
  * @brief TODO
  *
  * 时间复杂度: TODO
  */
  int reverse(int x) {
    bool flag = x < 0;  // 正负标记
    if (flag) x = -x;   // 取绝对值
    string s, int_max, int_min;
    s = to_string(x);
    int_max = to_string(INT_MAX);
    int_min = to_string(INT_MIN);
    s.erase(s.find_last_not_of('0') + 1); // 删除末尾'0'
    std::reverse(s.begin(), s.end());     // 反转s
    if (!flag) {
      if (s <= int_max) {
        return atoi(s.c_str());
      } else {
        return 0;
      }
    } else {
      s = "-" + s;
      if (s <= int_min) {
        return atoi(s.c_str());
      } else {
        return 0;
      }
    }
  }

};

// AC
class Solution_3 {
 public:
  /**
  * @brief 将x转换成string类型, 借助字符串操作完成反转
  *
  * 时间复杂度: O(log|x|)
  *
  * 操作顺序:
  *   1. 使用to_string()将x转换成s;
  *   2. 删除s末尾的0字符, 当s中只有一个字符'0'时, 不要删除;
  *   3. 使用std::reverse()将s反转
  *   4. 当x为正数时:
  *       a) 如果s的长度小于int_max的长度, 说明反转后的x的数位少于INT_MAX, 从而不会超出
  *     上限; 或者说s的长度等于int_max的长度(不可能出现大于的情况), 此时比较字符串s和
  *     int_max就能确定反转后的x是否会超出上限INT_MAX;
  *       b) 确定反转后的x不会超出上限后, 通过atoi()将s转换回int类型并返回; 否则返回0.
  *   5. 当x为负数时:
  *       a) 反转后的s的最后一个字符是负号'-', 需要将其删除, 以确保s中都是数字字符;
  *       b) 如果s的长度小于int_min_abs的长度, 说明反转后的x的数位少于INT_MIN, 从而不会
  *     超出下限; 或者说s的长度等于int_min_abs的长度(不可能出现大于的情况), 此时比较字符串
  *     s和int_min_abs就能确定反转后的x是否会超出下限INT_MIN;
  *       b) 确定反转后的x不会超出下限后, 通过atoi()将s转换回int类型并返回其相反数; 否则
  *     返回0.
  *
  * 算法时间复杂度和x的位数成正比, 而整数x大约有log(|x|)位数字, 因此时间复杂度为O(log|x|)
  */
  int reverse(int x) {
    string int_max = "2147483647";
    string int_min_abs = "2147483648";
    string s = to_string(x);
    int pos_last_not_zero = s.find_last_not_of('0');
    // 如果s=="0", 则不能删除
    if (pos_last_not_zero != string::npos)
      s.erase(pos_last_not_zero + 1); // 删除末尾'0'
    std::reverse(s.begin(), s.end());     // 反转s
    if (x > 0) {
      if (s.size() < int_max.size() || s <= int_max) {
        return atoi(s.c_str());
      } else {
        return 0;
      }
    } else {
      s.erase(s.size() - 1);  // 去掉末尾负号'-'
      if (s.size() < int_min_abs.size() || s <= int_min_abs) {
        return -atoi(s.c_str());
      } else {
        return 0;
      }
    }
  }

};

// AC
class Solution_4 {
 public:
  /**
  * @brief 借助模10和除10运算, 依次取出x的末位数字并用以组建新值
  *
  * 时间复杂度: O(log|x|)
  *
  * 题目指明系统不支持超过32位的整型, 因此在使用上一轮的res和本轮计算得到的digit来更新res
  * 值前, 就要提前考虑本轮更新是否会导致算术溢出.
  *
  * 考虑x为正数的情况: (已知INT_MAX等于2147483647)
  *   1. 如果上一轮更新后res值超过214748364, 即res>=214748365, 则本轮无论digit值为几,
  *   表达式`res*10+digit`都将超过INT_MAX;
  *   2. 如果上一轮更新后res值等于214748364, 则本轮当digit等于8或9时, 将会导致表达式
  *   `res*10+digit`超过INT_MAX; 然而值得注意的是, digit在这一轮不可能取到8或9, 事实上,
  *   它将不可能取到大于1的任何个位数值, 这是由x本身是一个不超过INT_MAX的值所决定的.
  *   3. 如果上一轮更新后res值小于214748364, 则本轮可以放心, 更新res值的表达式必不会出现
  *   溢出.
  *   ===> 综上, 当上一轮更新后res值超过214748364(即INT_MAX/10)时, 本轮res更新必会溢出,
  *   否则, 必不会溢出. 依照题目要求, 对于将出现算术溢出的情况, 应直接返回0.
  *
  * 对于x为负数的情况, 可以得出类似的结论: 当上一轮更新后res值低于(INT_MIN/10)时, 本轮res
  * 更新必会导致溢出, 否则, 必不会溢出.
  *
  * 算法时间复杂度和x的位数成正比, 而整数x的位数大约为log|x|, 因此时间复杂度为O(log|x|).
  */
  int reverse(int x) {
    int res = 0;
    while (x != 0) {
      if (res < INT_MIN / 10 || res > INT_MAX / 10) {
        return 0;
      }
      int digit = x % 10;
      x /= 10;
      res = res * 10 + digit; // 组建新值
    }
    return res;
  }

};

int main() {
  Solution_3 sol;
  // int x = -2147483648;
  int x = 0;
  cout << "result: " << sol.reverse(x);
}