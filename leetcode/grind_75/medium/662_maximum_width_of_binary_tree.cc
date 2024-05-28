// 第一反應: 從root開始, BFS, 每一層找最長的寬
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
  int widthOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    long long max_width = 1;
    queue<pair<TreeNode*, long long>> q;

    q.push({ root,0 });
    while (!q.empty())
    {
      long long current_q_size = q.size();

      long long front = q.front().second;
      long long back = q.back().second;

      max_width = max(max_width, back - front + 1);

      for (int i = 0; i < current_q_size; i++) {
        pair<TreeNode*, long long> p = q.front();
        long long idx = p.second - front;
        q.pop();

        if(p.first->left != nullptr) q.push({p.first->left, idx * 2 + 1});
        if(p.first->right != nullptr) q.push({p.first->right, idx * 2 + 2});
      }

    }
    return max_width;

  }
};