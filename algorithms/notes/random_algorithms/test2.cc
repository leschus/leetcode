// 测试sort()函数对结构数组进行排序
// 使用类封装一系列操作

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct kv_pair { int k, v; kv_pair(int a, int b) : k(a), v(b) {}};

class Test {
 public:
  void Sort(vector<int> a) {
    int n = a.size();
    v.reserve(n);
    for (int i = 0; i < n; i++) {
      // 注意: reserve()只是预定了一部分空间, 避免多次push_back()时需要频繁扩容.
      // 这并不意味着调用reserve(n)就马上为对象分配了大小为n的空间
      // 所以之后插入元素还是得用push_back(), 而不能够直接用[]和赋值运算符
      // v[i].k = 1;
      // v[i].v = a[i];
      v.push_back(kv_pair(1, a[i]));
    }
    for_each(v.begin(), v.end(), [](const kv_pair &n) {
        cout << "(" << n.k << ", " << n.v << ") "; });
    cout << endl;
  }

 private:
  vector<kv_pair> v;
  // static bool cmp(const kv_pair &lhs, const kv_pair &rhs) {
  //   return lhs.k < rhs.k;
  // }
};

int main() {
  Test t;
  vector<int> a = {5, 4, 3, 2, 1};
  t.Sort(a);
}