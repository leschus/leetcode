// Source: https://leetcode-cn.com/problems/symmetric-tree
// Author: Shihao Liu
// Date: 2021-12-03

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
  * @brief 迭代版本, 队列实现
  *
  * 时间复杂度: O(n)
  */

  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
      return true;
    } else if (root->left == nullptr && root->right == nullptr) {
      return true;
    } else if (root->left == nullptr || root->right == nullptr) {
      return false;
    }
    queue<TreeNode*> q1, q2;
    TreeNode *p1, *p2;
    q1.push(root->left);
    q2.push(root->right);
    // q1, q2中的元素个数始终是一样的, 因此只需对其中一个进行判断
    while (!q1.empty() /* && !q2.empty() */) {
      p1 = q1.front();
      p2 = q2.front();
      q1.pop();
      q2.pop();
      if (p1->val != p2->val) {
        return false;
      }
      if ((!p1->left ^ !p2->right) || (!p1->right ^ !p2->left)) {
        return false;
      }
      if (p1->left) {
        q1.push(p1->left);
        q2.push(p2->right);
      }
      if (p1->right) {
        q1.push(p1->right);
        q2.push(p2->left);
      }
    }
    // 循环退出时, 可断定两个队列均为空
    return true;
  }
};

class Solution_2 {
 private:
  // 内部递归函数
  bool isSymmetric(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    } else if (left == nullptr || right == nullptr || left->val != right->val) {
      return false;
    } else {
      return isSymmetric(left->left, right->right) &&
             isSymmetric(left->right, right->left);
    }
  }
 public:
  /**
  * @brief 递归
  *
  * 时间复杂度: O(n)
  */
  bool isSymmetric(TreeNode* root) {
    if (root) {
      return isSymmetric(root->left, root->right);
    }
    return false;
  }

};