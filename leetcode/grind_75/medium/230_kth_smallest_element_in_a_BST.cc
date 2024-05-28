// 第一反應: 因為bst的特性, 左子樹一定小於右子樹, 所以從最左下找, 跟著inorder順序找n個
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
public:
  int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int ans = 0;
    in_order_traversal(root, count, ans, k);
    return ans;
  }
  // 不用儲存拜訪的順序所以取目標就可以, 不然是要用vector<int> 然後抓到目標的位置
  void in_order_traversal(TreeNode* root, int& count, int& ans, int k) {
    if(root == nullptr) return;
    in_order_traversal(root->left, count,ans,k);
    count++;
    if(count == k) {
      ans = root->val;
      return;
    }
    in_order_traversal(root->right, count,ans,k);
  }
};