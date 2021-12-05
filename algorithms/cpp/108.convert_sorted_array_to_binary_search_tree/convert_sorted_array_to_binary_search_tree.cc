// Source: https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
// Author: Shihao Liu
// Date: 2021-12-05


#include <vector>
#include <cstdlib>
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
  * @brief 分治
  *
  * @时间复杂度 O(n)
  */
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return DFS(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode *DFS(vector<int> &nums, int begin, int end) {
    if (begin > end) {
      return nullptr;
    }
    int mid = (begin + end) / 2; // 总是下取整
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = DFS(nums, begin, mid - 1);
    node->right = DFS(nums, mid + 1, end);
    return node;
  }

};


class Solution_2 {
 public:
  /**
  * @brief 分治
  *
  * @时间复杂度 O(n)
  */
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return DFS(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode *DFS(vector<int> &nums, int begin, int end) {
    if (begin > end) {
      return nullptr;
    }
    int mid = (begin + end + 1) / 2; // 总是上取整
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = DFS(nums, begin, mid - 1);
    node->right = DFS(nums, mid + 1, end);
    return node;
  }

};


class Solution_2 {
 public:
  /**
  * @brief 分治
  *
  * @时间复杂度 O(n)
  */
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return DFS(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode *DFS(vector<int> &nums, int begin, int end) {
    if (begin > end) {
      return nullptr;
    }
    int mid = (begin + end + rand() % 2) / 2; // 随机决定上取整还是下取整
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = DFS(nums, begin, mid - 1);
    node->right = DFS(nums, mid + 1, end);
    return node;
  }

};