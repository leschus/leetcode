// Source: https://leetcode-cn.com/problems/path-sum
// Author: Shihao Liu
// Date: 2021-12-07

#include <queue>
#include <algorithm>
#include "cpp/definitions.h"
using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 递归, 深度优先搜索
  *
  * @时间复杂度 O(n)
  */
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    if (!root->left && !root->right) {
      return root->val == targetSum;
    } else {
      return hasPathSum(root->left, targetSum - root->val)
            || hasPathSum(root->right, targetSum - root->val);
    }
  }

};

class Solution_2 {
 public:
  /**
  * @brief 迭代, 广度优先搜索
  *
  * @时间复杂度 O(n)
  */
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
      return false;
    }
    queue<pair<TreeNode *, int>> que;
    que.push(make_pair(root, 0));
    TreeNode *node;
    int sum;
    while (!que.empty()) {
      node = que.front().first;
      sum = que.front().second;
      que.pop();
      sum += node->val;
      if (!node->left && !node->right && sum == targetSum) {
        return true;
      }
      if (node->left) {
        que.push(make_pair(node->left, sum));
      }
      if (node->right) {
        que.push(make_pair(node->right, sum));
      }
    }
    return false;
  }

};