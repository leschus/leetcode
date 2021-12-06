// Source: https://leetcode-cn.com/problems/merge-two-sorted-lists
// Author: Shihao Liu
// Date: 2021-11-21

#include "cpp/definitions.h"

// AC
class Solution_1 {
 public:
  /**
  * @brief 递归, 减而治之
  *
  * 时间复杂度: O(m+n), m, n分别为链表l1和l2的长度
  *
  * 将两个升序链表合并成一个升序链表， 使用现有结点而不是创建新结点
  *
  * 比较两个链表的首结点的大小, 其中较小者可以确定为结果链表中的头号结点;
  * 例如, l1->val < l2->val, 则l1所指结点为结果链表的头结点, 此时问题等价于将
  * 首结点为l1->next的链表和首结点为p2的链表合并, 并将合并后的链表接在l1所指结
  * 点的后边. 这样一来, 问题的规模就减小了1.
  * 最多递归 m + n 轮, 就可以得到结果, 其中m和n分别为两个链表的长度
  * 递归出口为: l1为空或者l2为空.
  *
  */
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     if (l1 == nullptr) {
       return l2;
     } else if (l2 == nullptr) {
       return l1;
     }
     if (l1->val <= l2->val) {
       l1->next = mergeTwoLists(l1->next, l2);
       return l1;
     } else {
       l2->next = mergeTwoLists(l1, l2->next);
       return l2;
     }
   }

};