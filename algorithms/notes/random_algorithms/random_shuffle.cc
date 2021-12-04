// Author: Shihao Liu
// Date: 2021-12-03

// 随机洗牌算法

#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 问题描述:
//    输入一个含n个元素的数组a, 要求将其中的元素顺序重新排列, 且出现任意一种重排结果
//    的概率都是相等的. 也就是说, 都是1/(n!).


// 解法1:
// 借助辅助数组h, 数组中包含表示优先级的随机值. 如h[i]被视作a[i]的优先级. 随后根据每个
// 元素的优先级大小对数组a进行重新排列.

/* 这种解法的实现最好是将数组a和h的元素封装在一起, 这样进行排序时方便些
   因此, 舍弃了下面这个最初的实现思路...
*/
// class Solution_1 {
//  private:
//   vector<int> h;
//   static bool cmp(...) {
//     ...
//   }
//  public:
//   /**
//   * @brief TODO
//   *
//   * 时间复杂度: TODO
//   */
//   void random_shuffle(vector<int> a, int n) {
//     // 为辅助数组预分配空间并使用随机数
//     h.reserve(n);
//     for (int i = 0; i < n; i++) {
//       // 产生一个[0, RAND_MAX]区间内的随机整数
//       // 注意, 多次调用rand()可能产生重复的数, 而这会导致最终结果的等概率性遭到破坏.
//       // 下一个版本的解法将修复这个问题
//       h[i] = rand();
//     }
//     // 数组a中元素依据数组h中指定的优先级进行重新排序
//     ...
//   }
// };


class Solution_1 {
 public:
  /**
  * @brief 借助含随机值的辅助数组为待重排数组的元素提供优先级
  *
  * 时间复杂度: O(nlogn), 因为用到了排序
  */
  void random_shuffle(vector<int> &a) {
    int n = a.size();
    v.reserve(n);
    for (int i = 0; i < n; i++) {
      // 产生一个[0, RAND_MAX]区间内的随机整数
      // 注意, 多次调用rand()可能产生重复的数, 而这会导致最终结果的等概率性遭到破坏.
      // 下一个版本的解法将修复这个问题
      v.push_back(node(a[i], rand()));
    }
    // 数组a中元素依据数组h中指定的优先级进行重新排序
    sort(v.begin(), v.end(), cmp);
    // 把排序后的元素拷贝回数组a
    for (int i = 0; i < n; i++) {
      a[i] = v[i].val;
    }
  }

 private:
  struct node {
    int val;
    int priority;
    node(int v, int p) : val(v), priority(p) {}
  };
  static bool cmp(const node &lhs, const node &rhs) {
    return lhs.priority < rhs.priority;
  }
  vector<node> v;

};

// TODO: 对解法1的优化, 修复多次调用rand()可能出现重复元素的问题
// 提示: 使用set. (set有自动去重功能)


// 解法2:
// 不借助辅助数组, 原地重排

class Solution_2 {
 public:
  /**
  * @brief TODO
  *
  * 时间复杂度: TODO
  */
  void random_shuffle(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
      swap(a[i], a[random(i, n - 1)]);
    }
  }

 private:
  // 返回[a, b]区间内的一个随机整数
  int random(int a, int b) {
    return rand() % (b - a + 1) + a;
  }

};


int main() {
  srand(time(0));
  vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Solution_1 sol1;
  Solution_2 sol2;
  sol1.random_shuffle(a);
  for_each(a.begin(), a.end(), [](int x){ cout << x << " "; }); // 有误....TODO
  cout << endl;
  sol2.random_shuffle(a);
  for_each(a.begin(), a.end(), [](int x){ cout << x << " "; });
  cout << endl;
}