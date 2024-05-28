#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0) return nullptr;

    return buildBST(nums.begin(), nums.end());
  }
  TreeNode* buildBST(vector<int>::const_iterator start, vector<int>::const_iterator end) {
    if (start >= end) return nullptr;

    vector<int>::const_iterator middle = start + ((end - start) / 2);
    TreeNode* node = new TreeNode(*middle);
    node->left = buildBST(start, middle);
    node->right = buildBST(middle + 1, end);
    return node;

  }
};