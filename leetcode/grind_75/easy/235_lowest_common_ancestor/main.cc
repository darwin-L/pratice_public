// 從兩個點個別延伸出去直到碰到彼此(目前值收斂至目標值) 
// 這題的列舉的條件很重要
// p != q -> 
// p q都會存在於BST
// 所有值都為唯一 -> 可以不用考慮同值的時候的順序問題
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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* current = root;
    while (true)
    {
      // 不使用 <= 因為 當等於的時候直接就是該點, 並且由於 p q 都會存在於BST 可以直接收斂至答案
      if (p->val < current->val && q->val < current->val) {
        current = current->left;
      }
      else if (p->val > current->val && q->val > current->val) {
        current = current->right;
      }
      else {
        break;
      }
    }
    return current;

  }
};