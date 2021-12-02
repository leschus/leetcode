// Source: https://leetcode-cn.com/problems/same-tree
// Author: Shihao Liu
// Date: 2021-12-02

#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution_1 {
 public:
  /**
  * @brief 递归, 深度优先遍历
  *
  * 时间复杂度: O(min{n1, n2}), n1, n2分别为两棵树的结点个数
  *
  * 1. 若p, q同时为空树, 返回true;
  * 2. 若p, q一个为空树, 另一个非空, 返回false;
  * 3. 若p, q均为非空树, 比较两者的根结点值:
  *     a. 若相等, 则递归地分别比较p和q的左子树以及右子树;
  *     b. 若不等, 返回false;
  */
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    } else if (p == nullptr || q == nullptr) {
      return false;
    } else if (p->val != q->val) {
      return false;
    } else {
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
  }

};


class Solution_2 {
 public:
  /**
  * @brief 迭代, 广度优先遍历
  *
  * 时间复杂度: O(min{n1, n2}), n1, n2分别为两棵树的结点个数
  */
  bool isSameTree(TreeNode *p, TreeNode *q) {
    queue<TreeNode*> que;
    TreeNode *pn1, *pn2;
    que.push(p);
    que.push(q);
    while (!que.empty()) {
      pn1 = que.front();
      que.pop();
      pn2 = que.front();
      que.pop();
      if (!pn1 && !pn2) { // 均为空树
        continue;
      } else if (!pn1 || !pn2 || (pn1->val != pn2->val)) {
        // 仅有一棵为空树或均非空树但根结点值不相等
        return false;
      } else {
        // 均为非空树, 且根结点值也相等
        // 将左右孩子依次入队, 以供下轮比较
        que.push(pn1->left);
        que.push(pn2->left);
        que.push(pn1->right);
        que.push(pn2->right);
      }
    }
    return true;
  }

};