// 第一反應: 遞迴找全部, 用一個flag判斷要先找左邊還是先找右邊, 
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
  bool recursive(TreeNode* left, TreeNode* right) {
    if (!left && !right) {
      return true;
    }
    if (!left || !right) {
      return false;
    }
    // 用flag會比較難寫, 因為每個recursive之後左右要調換
    // 直接用遞迴然後將他們的左右以及val判斷寫在同一個判斷式裡面並用邏輯操作連起來
    return (left->val == right->val) && recursive(left->left, right->right) && recursive(left->right, right->left);
  }
  bool isSymmetric(TreeNode* root) {
    if (root == NULL) {
      return true;
    }
    return recursive(root->left, root->right);
  }
};
// TODO: iteration寫法