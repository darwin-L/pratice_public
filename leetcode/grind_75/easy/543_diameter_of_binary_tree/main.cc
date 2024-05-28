// 第一反應: 從root找最長樹高, 也就是找左右就可以了, 廣度優先, 時間複雜O(n)
// 要的不是樹高而是每個點之間的最長距離
// 因為是樹且只要回傳最長的即可, 遞迴可以用, 不用將所有點跟點之間的距離弄成矩陣
// corner-case 
//       *
//    *    *
//  *  *
// *  *
//*  *

#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 */
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
  int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    recursive_method(root,ans);
    return ans;
  }
  int recursive_method(TreeNode* root, int& depth) {
    if (root == NULL) return 0;
    int left = recursive_method(root->left, depth);
    int right = recursive_method(root->right, depth);
    depth = max(depth, left + right);
    return max(left, right) + 1;
  }
};
