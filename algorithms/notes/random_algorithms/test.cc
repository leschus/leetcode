// 测试sort()函数对结构数组进行排序

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct kv_pair {
  int k;
  int v;
};

bool cmp(const kv_pair &lhs, const kv_pair &rhs) {
  return lhs.k < rhs.k;
}

int main() {
  vector<kv_pair> vec = {{5, 1}, {4, 2}, {3, 3}, {2, 4}, {1, 5}};
  sort(vec.begin(), vec.end(), cmp);
  for_each(vec.begin(), vec.end(), [](const kv_pair &x){ cout << x.v << endl; });
  cout << endl;
}