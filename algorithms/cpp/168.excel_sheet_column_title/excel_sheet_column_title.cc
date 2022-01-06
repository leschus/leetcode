// Source: https://leetcode-cn.com/problems/excel-sheet-column-title
// Author: Shihao Liu
// Date: 2022-01-02

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 26进制
  *
  * @时间复杂度 O(logn), 底数为26
  */
  string convertToTitle(int columnNumber) {
    char cs[10];
    int i = 0;
    while (columnNumber) {
      --columnNumber;
      cs[i] = columnNumber % 26 + 'A';
      columnNumber /= 26;
      ++i;
    }
    cs[i] = '\0';
    string s(cs);
    reverse(s.begin(), s.end());
    return s;
  }

};


int main() {
  int n1 = 1, n2 = 28, n3 = 701, n4 = 2147483647;
  Solution_1 sol;
  cout << sol.convertToTitle(n1) << endl;
  cout << sol.convertToTitle(n2) << endl;
  cout << sol.convertToTitle(n3) << endl;
  cout << sol.convertToTitle(n4) << endl;

}