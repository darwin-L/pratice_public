// 題目意思是從最右邊看而不是只拿右手邊的值, 別被範例誤導
#include<bits/stdc++.h>
using namespace std;
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
  void recrusive(TreeNode* root, int level, vector<int>& ans) {
    if (root == NULL) return;
    if (ans.size() < level)ans.push_back(root->val);
    // 兩邊都要處理, 因為如果當右邊沒有子樹的時候要拿左邊子樹的值
    recrusive(root->right, level + 1, ans);
    recrusive(root->left, level + 1, ans);
  }
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    recrusive(root, 1, ans);
    return ans;
  }
};