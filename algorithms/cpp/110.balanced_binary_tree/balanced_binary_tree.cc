// Source: https://leetcode-cn.com/problems/balanced-binary-tree
// Author: Shihao Liu
// Date: 2021-12-06

#include <algorithm>
#include "cpp/definitions.h"
using namespace std;


class Solution_1 {
 public:
  /**
  * @brief 自顶向下
  *
  * @时间复杂度 O(nlogn): isBalanced()遍历n个结点, depth()最坏递归层数为O(h) = O(logn)
  *
  * 自顶向下计算每个结点的深度会导致大量的重复计算
  */
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
        return true;
      } else {
        return isBalanced(root->left) && isBalanced(root->right)
              && abs(depth(root->left) - depth(root->right)) <= 1;
      }
  }

 int depth(TreeNode *root) {
   if (root) {
     int ldepth = depth(root->left);
     int rdepth = depth(root->right);
     return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
   }
   return 0;
 }

};

class Solution_2 {
 public:
  /**
  * @brief 自底向上
  *
  * @时间复杂度 O(n)
  */
  bool isBalanced(TreeNode *root) {
    return depth(root) != -1;
  }

 private:
  int depth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int ldepth, rdepth;
    if ((ldepth = depth(root->left)) == -1 ||
        (rdepth = depth(root->right)) == -1 ||
        abs(ldepth - rdepth) >= 2) {
      return -1;
    }
    return max(ldepth, rdepth) + 1;
  }

};