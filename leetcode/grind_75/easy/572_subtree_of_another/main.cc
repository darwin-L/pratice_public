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
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {

    // corner-case, root為空或子樹與原本樹相同
    if (root == NULL) return false;
    if (isSameTree(root, subRoot)) return true;

    //注意這邊已經呼叫判斷子樹的方法 , 如果使用isSameTree的話 corner-case會出現在
    // root = [1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,2]
    // subRoot = [1,null,1,null,1,null,1,null,1,null,1,2]
    // 偏一邊的linked-list樹並且子樹離root樹高差2以上的輸入
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
  bool isSameTree(TreeNode* root, TreeNode* subRoot) {
    if (root == NULL && subRoot == NULL) return true;
    if (root == NULL || subRoot == NULL) return false;

    if (root->val != subRoot->val) return false;

    return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
  }
};