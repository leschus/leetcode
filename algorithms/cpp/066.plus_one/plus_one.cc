// Source: https://leetcode-cn.com/problems/plus-one
// Author: Shihao Liu
// Date: 2021-11-25

#include <vector>

using namespace std;

// AC
class Solution_1 {
 public:
  /**
  * @brief 逆序遍历, 模拟列竖式加法
  *
  * 时间复杂度: O(n)
  *
  * 模拟列竖式进行两数相加.
  *
  * 从后向前处理(i初始化为digits.size()-1), 若digits[i]==9, 则将其置为0, i--, 并
  * 进入下轮处理; 否则, digits[i]++, 并退出循环.
  * 循环体要求i>=0, 否则退出循环. 若由于i<0而导致循环退出, 则需要在数组第一个元素
  * 前插入一个1. ==> 由于vector没有push_front方法, 因此只能将所有元素右移一个位
  * 置以腾出第一个位置.
  */
  vector<int> plusOne(vector<int> &digits) {
    int i = digits.size() - 1;
    while (i >= 0) {
      if (digits[i] == 9) {
        digits[i] = 0;
        i--;
      } else {
        digits[i]++;
        break;
      }
    }
    if (i < 0) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }

};