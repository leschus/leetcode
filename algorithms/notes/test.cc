#include <string>
#include <iostream>
#include <vector>
using namespace std;

int Index(string s, string t) {
  int i = 0, j = 0; // 下标从0开始
  while (i < s.size() && j < t.size()) {
    if (s[i] == t[j]) {
      i++; j++;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }
  if (j == t.size()) {
    return i - t.size();
  } else {
    return -1;
  }
}

vector<int> generate_next(string t) {
  vector<int> next(t.size());
  next[0] = -1;
  int i = 0, j = -1;
  while (i < t.size()) {
    if (j == -1 || t[i] == t[j]) {
      i++; j++;
      next[i] = j;
    } else {
      j = next[j];
    }
  }
  return next;
}

int Index_KMP(string s, string t) {
  vector<int> next = generate_next(t);
  for (int x: next) cout << x << " ";
  cout << endl;
  int i = -1, j = -1;
  int len1 = s.size(), len2 = t.size();
  // 注意: 直接将变量i和s.size()比较会有问题, 因为s.size()的返回类型size_t没有
  // 符号, 因此将int型的-1和size_t类型值进行比较, 将发生隐式向上类型转换, 导致
  // 参与比较的i值实际为UINT_MAX. ==>由此导致while()循环根本就不会进入!!
  while (i < len1 && j < len2) {
    if (j == -1 || s[i] == t[j]) {
      i++; j++;
    } else {
      j = next[j];
    }
  }
  if (j == len2) {
    return i - len2;
  } else {
    return -1;
  }
}

int main() {
  // 当t为空串时, 输出0. 即空串作为任何一个字符串的子串来说, 其第一个出现
  // 的位置总是下标0.
  // string s = "abc", t = "";
  // cout << Index(s, t) << endl;

  string t = "ababa";
  // vector<int> next = generate_next(t);
  // for (int x: next) cout << x << " ";
  // cout << endl;
  string s = "ababcababa";
  cout << Index_KMP(s, t) << endl;

  cout << Index(s, t) << endl;
}