// 手撕KMP算法

#include <string>
#include <vector>
#include <iostream>
using namespace std;

void kmp_init(const string &t, vector<int> &next) {
  int i = 0, j = -1, m = t.size();
  next[0] = -1;
  while (i < m - 1) {
    if (j == -1 || t[i] == t[j]) {
      i++;
      j++;
      next[i] = j;
    } else {
      j = next[j];
    }
  }
}

int kmp(const string &s, const string &t) {
  if (t.empty()) {
    return 0;
  }
  int n = s.size(), m = t.size();
  vector<int> next(m);
  kmp_init(t, next);
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (j == -1 || s[i] == t[j]) {
      i++;
      j++;
    } else {
      j = next[j];
    }
  }
  if (j == m) {
    return i - m;
  } else {
    return -1;
  }
}

int main() {
  cout << "手撸一次KMP算法, 看看能否一次PASS:\n";
  string s = "hello", t = "ll";
  cout << kmp(s, t) << endl;
  string ss(200, 'a'), tt(100, 'a');
  ss += 'b';
  tt += 'b';
  cout << tt << endl;
  cout << kmp(ss, tt) << endl;
}