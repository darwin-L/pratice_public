// 從root開始算, 廣度優先, 右邊先, 這個只能適用於perfect-binary-tree, 其他的要多很多檢查條件

#include <bits/stdc++.h>
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
  TreeNode* invertTree(TreeNode* root) {
    // 直接透過指標交換原本的樹
    std::stack<TreeNode*> root_ptr;
    root_ptr.push(root);
    while (!root_ptr.empty())
    {
      TreeNode* temp_node = root_ptr.top();
      root_ptr.pop();
      if(temp_node) {
        root_ptr.push(temp_node->right);
        root_ptr.push(temp_node->left);
        swap(temp_node->left, temp_node->right);
      }
    }
    return root;
  }
};