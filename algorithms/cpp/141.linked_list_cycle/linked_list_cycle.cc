// Source: https://leetcode-cn.com/problems/linked-list-cycle
// Author: Shihao Liu
// Date: 2021-12-17

#include <unordered_set>

#include "cpp/definitions.h"

using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 利用unordered_set(哈希表)的自动去重特性
  *
  * @时间复杂度 O(n)
  * @空间复杂度 O(n)
  */
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> s;
    ListNode *p = head;
    int i = 0;
    while (p) {
      s.insert(p);
      ++i;
      if (s.size() != i) {
        return true;
      }
      p = p->next;
    }
    return false;
  }
};

class Solution_2 {
 public:
  /**
  * @brief 快慢指针
  *
  * @时间复杂度 O(n)
  */
  bool hasCycle(ListNode *head) {
    if (!head) return false;
    ListNode *slow = head, *fast = head->next;
    while (fast != slow) {
      if (fast == nullptr || fast->next == nullptr) {
        return false;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    return true;
  }

};