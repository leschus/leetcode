// Source: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
// Author: Shihao Liu
// Date: 2021-12-01

#include "cpp/definitions.h"

class Solution_1 {
 public:
  /**
  * @brief 双指针遍历链表
  *
  * 时间复杂度: O(n)
  *
  * 从升序链表中删除重复元素, 使得每个元素只出现一次
  *
  * 遍历一遍链表, 维护一个指向当前结点的指针p和一个指向当前结点前继的指针pre.
  * 若p结点的值等于pre结点的值, 则删除p结点
  *
  * 对于空链表, 不做任何操作.
  */
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) { // 空链表
      return nullptr;
    }
    ListNode *pre = head, *p = head->next;
    while (p) {
      if (p->val == pre->val) { // 发现重复元素
        pre->next = p->next;
        delete p;
        p = pre->next; // 只更新p, 不需要更新pre
      } else {
        pre = p;
        p = p->next;
      }
    }
    return head;
  }

};