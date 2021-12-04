// 在线随机抽样

// 问题描述
//    从N个数中随机抽取M (M<=N) 个数, 要求每个数被抽取到的概率都相同 (即M/N).
//    并且N个数只能从头到尾遍历一遍, 访问过的数不能再被访问.

// 使用场景实例:
//    已知即将有10个流量按序到来, 要在这10个流量中随机选取3个并在其中投放广告,
//    每个流量被投放广告的概率应当相同, 该如何选取?

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

/** 使用生成器f生成要处理的n个数, 并从中随机等概率地选取m个数
 * @param n 要生成的数据总数
 * @param m 要选取的数据总数
 * @param f 随机数生成器
 * @return 返回选取的m个数
 * @note 每次调用生成器f将返回一个整数值
 */
template <typename Generator>
vector<int> RandomSelectOnline(int n, int m, Generator f) {
  vector<int> ans;
  ans.reserve(m);
  int t = m;
  for (int i = 0; i < n; i++) {
    int val = f();
    cout << "Got " << val << endl;
    // 生成一个[0, n - i - 1]内的随机整数, 该数小于t的概率为: t / (n - i)
    if ((rand() % (n - i)) < t) {
      cout << "Selected.\n";
      ans.push_back(val);
      t--;
    }
  }
  return ans;
}

// 随机整数生成器, 取值范围[1, 100]
int random() {
  return rand() % 100 + 1;
}

int main() {
  srand(time(0));
  vector<int> selected = RandomSelectOnline(10, 3, random);
  for (int x: selected) {
    cout << x << " ";
  }
  cout << endl;
}