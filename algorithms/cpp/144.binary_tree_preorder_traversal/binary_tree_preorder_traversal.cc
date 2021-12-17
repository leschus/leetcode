// Source: https://leetcode-cn.com/problems/binary-tree-preorder-traversal
// Author: Shihao Liu
// Date: 2021-12-17

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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(root, res);
    return res;
  }

 private:
  void dfs(TreeNode* root, vector<int>& vec) {
    if (root) {
      vec.push_back(root->val);
      dfs(root->left, vec);
      dfs(root->right, vec);
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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode *p = root;
    while (p || !st.empty()) {
      if (p) {
        res.push_back(p->val);
        st.push(p);
        p = p->left;
      } else {
        p = st.top()->right;
        st.pop();
      }
    }
    return res;
  }

};