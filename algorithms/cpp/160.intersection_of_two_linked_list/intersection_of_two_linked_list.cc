// Source: https://leetcode-cn.com/problems/intersection-of-two-linked-list
// Author: Shihao Liu
// Date: 2021-12-18

#include <stack>

#include "cpp/definitions.h"

using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 使用栈特性进行逆序比较
  *
  * @时间复杂度 O(m+n)
  * @空间复杂度 O(m+n)
  */
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    stack<ListNode*> sa, sb;
    ListNode* p;
    for (p = headA; p != nullptr; p = p->next) {
      sa.push(p);
    }
    for (p = headB; p != nullptr; p = p->next) {
      sb.push(p);
    }
    // assert(p == nullptr);
    while (!sa.empty() && !sb.empty()) {
      if (sa.top() != sb.top()) { // 从后向前找首个相异的结点
        break; // 返回其后一个结点
      }
      p = sa.top();
      sa.pop();
      sb.pop();
    }
    return p;
  }

};

class Solution_2 {
 public:
  /**
  * @brief 双指针
  *
  * @时间复杂度 O(m+n)
  * @空间复杂度 O(1)
  */
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* pa = headA, *pb = headB;
    while (pa != pb) {
      pa = pa ? pa->next : headB;
      pb = pb ? pb->next : headA;
    }
    return pa;
  }

};