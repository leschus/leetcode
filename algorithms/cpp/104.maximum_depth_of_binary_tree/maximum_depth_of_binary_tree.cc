// Source: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
// Author: Shihao Liu
// Date: 2021-12-04

#include <queue>
#include "cpp/definitions.h"
using namespace std;


class Solution_1 {
 public:
  /**
  * @brief 深度优先搜索, 递归
  *
  * @时间复杂度 O(n)
  * @空间复杂度 O(h), h为树高
  */
  int maxDepth(TreeNode *root) {
    if (root) {
      int lmax = maxDepth(root->left);
      int rmax = maxDepth(root->right);
      return lmax > rmax ? (lmax + 1) : (rmax + 1);
    }
    return 0;
  }
};

class Solution_2 {
 public:
  /**
  * @brief 广度优先搜索, 层序遍历, 队列, 非递归
  *
  * @时间复杂度 O(n)
  * @空间复杂度 O(n)
  */
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    queue<TreeNode*> que;
    que.push(root);
    int max_depth = 0;
    TreeNode *p;
    while (!que.empty()) {
      while (!que.empty()) {
        p = que.front();
        que.pop();
        if (p->left) {
          que.push(p->left);
        }
        if (p->right) {
          que.push(p->right);
        }
      }
      max_depth++;
    }
    return max_depth;
  }

};
