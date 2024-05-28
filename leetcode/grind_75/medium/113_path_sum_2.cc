// 第一反應: 從root開始左右子樹遞迴, 因為值可以是負的, 所以不能找到答案就停(X)
// root-to-leaf 要到尾端, 所以相對簡單, 不會有中途的線段符合條件
#include<bits/stdc++.h>
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
private:
  vector<vector<int>> ans;
public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int>init_path;
    // 因為一定要從root開始(題目限制), 所以不用兩條線開始弄
    recursive(root, targetSum, init_path);
    return ans;
  }
  void recursive(TreeNode* root, int current_sum, vector<int> path) {
    if (root == nullptr) return;
    current_sum -= root->val;
    path.push_back(root->val);
    // [1,2] target = 1 => []. [1] target = 1 => [1]
    if (current_sum == 0 && (root->left == nullptr) && (root->right == nullptr)) {
      ans.push_back(path);
    }
    
    recursive(root->left, current_sum, path);
    recursive(root->right, current_sum, path);
    // 記得pop, 讓路線回去
    path.pop_back();

  }
};