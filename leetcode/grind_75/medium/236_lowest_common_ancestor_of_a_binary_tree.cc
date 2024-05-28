// 注意條件: All Node.val are unique. p != q.  p and q will exist in the tree.
// 第一反應: 從root找左右, 當發現任一點的val與p q重複, 紀錄該點的上一點, 並紀錄路徑
// 當路徑沒有重疊, 祖先是第一個發現的點的上一點
// 當路徑有重疊, 祖先是第一個發現的點
#include<bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);


    // 可以直接用左右子樹判斷路徑, 因為條件一
    // 路徑沒有重疊, 回傳沒有重疊的第一個祖先
    if(left != nullptr && right != nullptr) return root;
    if(left != nullptr) return left;
    return right;
    // return !left ? right : (!right ? left : root); same as above
  }
};