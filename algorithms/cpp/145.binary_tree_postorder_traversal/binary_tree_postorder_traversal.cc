// Source: https://leetcode-cn.com/problems/binary-tree-postorder-traversal
// Author: Shihao Liu
// Date: 2021-12-18

#include <stack>
#include <vector>

#include "cpp/definitions.h"

using namespace std;

class Solution_1 {
 public:
  /**
  * @brief 递归, 深度优先搜索
  *
  * @时间复杂度 O(n)
  */
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(root, res);
    return res;
  }

 private:
  void dfs(TreeNode* root, vector<int>& vec) {
    if (root) {
      dfs(root->left, vec);
      dfs(root->right, vec);
      vec.push_back(root->val);
    }
  }

};


class Solution_2 {
 public:
  /**
  * @brief 迭代, 深度优先搜索
  *
  * @时间复杂度 O(n)
  */
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    TreeNode *p = root, *c;
    stack<TreeNode*> st;
    while (p || !st.empty()) {
      if (p) {
        st.push(p);
        p = p->left;
      } else {
        p = st.top();
        // 右子树为空或右子树刚被访问过
        if (p->right == nullptr || p->right == c) {
          res.push_back(p->val);
          st.pop();
          c = p;
          p = nullptr; // 赋空
        } else {
          p = p->right;
        }
      }
    }
  }

};