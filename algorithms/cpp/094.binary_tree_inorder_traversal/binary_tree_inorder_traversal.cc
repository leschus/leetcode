// Source: https://leetcode-cn.com/problems/binary-tree-inorder-traversal
// Author: Shihao Liu
// Date: 2021-12-02

#include <vector>
#include <stack>
#include "cpp/definitions.h"
using namespace std;


class Solution_1 {
 private:
  // 内部递归函数
  void inorder(TreeNode *root, vector<int> &v) {
    if (root) {
      inorder(root->left, v);
      v.push_back(root->val);
      inorder(root->right, v);
    }
  }
 public:
  /**
  * @brief 递归版本
  *
  * 时间复杂度: O(n)
  */
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorder(root, result);
    return result;
  }

};

class Solution_2 {
 public:
  /**
  * @brief 迭代版本(借助栈实现)
  *
  * 时间复杂度: O(n)
  */
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode *p = root;
    while (p || !st.empty()) {
      if (p) {
        st.push(p);
        p = p->left;
      } else {
        p = st.top();
        st.pop();
        result.push_back(p->val);
        p = p-> right;
      }
    }
    return result;
  }

};