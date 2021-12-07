// Source: https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
// Author: Shihao Liu
// Date: 2021-12-07

#include <algorithm>
#include <queue>
#include "cpp/definitions.h"
using namespace std;


class Solution_1 {
 public:
  /**
  * @brief 递归, 深度优先搜索
  *
  * @时间复杂度 O(n)
  */
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    } else {
      if (root->left && root->right) {
        return min(minDepth(root->left), minDepth(root->right)) + 1;
      } else if (!root->left) {
        return minDepth(root->right) + 1;
      } else {
        return minDepth(root->left) + 1;
      }
    }
  }

};

class Solution_2 {
 public:
  /**
  * @brief 迭代, 广度优先搜索, 队列
  *
  * @时间复杂度 O(n)
  */
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    queue<pair<TreeNode *, int>> que;
    que.push(make_pair(root, 1));
    TreeNode *p;
    int depth;
    while (!que.empty()) {
      p = que.front().first;
      depth = que.front().second;
      que.pop();
      if (!p->left && !p->right) {
        return depth;
      }
      if (p->left) {
        que.push(make_pair(p->left, depth + 1));
      }
      if (p->right) {
        que.push(make_pair(p->right, depth + 1));
      }
    }
    return 0;
  }

};