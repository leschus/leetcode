// reverse_bits.cc
// Source: https://leetcode-cn.com/problems/reverse-bits
// Author: Shihao Liu
// Date: 2022-01-07

#include <bits/stdc++.h>

class Solution_1 {
 public:
  /**
  * @brief 位运算
  *
  * @时间复杂度 O(logn)
  */
  uint32_t reverseBits(uint32_t n) {
      uint32_t mask = 0x80000000, res = 0;
      while (n) {
        if (n & 1) {
          res |= mask;
        }
        n >>= 1;
        mask >>= 1;
      }
      return res;
  }

};

class Solution_2 {
 private:
  const uint32_t M1 = 0x55555555;
  const uint32_t M2 = 0x33333333;
  const uint32_t M3 = 0x0f0f0f0f;
  const uint32_t M4 = 0x00ff00ff;
 public:
  /**
  * @brief 位运算分治
  *
  * @时间复杂度 O(1)
  */
  uint32_t reverseBits(uint32_t n) {
    // n的奇数位和偶数位互换位置
    n = (n >> 1) & M1 | (n & M1) << 1;
    // 每两个数位一组，奇数组和偶数组互换位置
    n = (n >> 2) & M2 | (n & M2) << 2;
    // 每四个数位一组，奇数组和偶数组互换位置
    n = (n >> 4) & M3 | (n & M3) << 4;
    // 每八个数位一组，基数组和偶数组互换位置
    n = (n >> 8) & M4 | (n & M4) << 8;
    // 最后将前16个数位和后16个数位互换位置
    return n << 16 | n >> 16;
  }

};