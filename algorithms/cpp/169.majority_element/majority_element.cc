// Source: https://leetcode-cn.com/problems/majority-element
// Author: Shihao Liu
// Date: 2022-01-03

#include <vector>
#include <unordered_map>
using namespace std;

class Solution_1 {
 public:
  /**
  * @brief hashtable
  *
  * @时间复杂度 O(n)
  * @空间复杂度 O(n)
  */
  public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int x: nums) {
            if (m.find(x) == m.end()) {
                m.insert(make_pair(x, 1));
            } else {
                ++m[x];
            }
        }
        int maxn = 0, maxc = 0;
        for (auto p: m) {
            if (p.second > maxc) {
                maxc = p.second;
                maxn = p.first;
            }
        }
        return maxn;
    }
};