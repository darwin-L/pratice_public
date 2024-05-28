// 第一反應: BFS, 從root開始, 每一層往下深度+1, 同個深度的放到同個vector裡面的元素
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



// BFS
class Solution {
public:
  vector<vector<int>> ans;
  vector<vector<int>> levelOrder(TreeNode* root) {
    BFS_vector(root, 0);
    return ans;
  }
  void BFS_vector(TreeNode* root, int depth) {
    if (root == NULL) return;
    // 每一個深度的初始vector
    if (ans.size() == depth) ans.push_back(vector<int>());

    ans[depth].push_back(root->val);
    BFS_vector(root->left, depth + 1);
    BFS_vector(root->right, depth + 1);
  }
};

// using queue
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if (root == NULL)return ans;
    queue<TreeNode*>q;
    q.push(root);
    while (!q.empty()) {
      int current_depth_size = q.size();
      vector<int>v;
      // 每跑一次queue, current_depth_size都會變動, 變動的量與pop的量會相等
      for (int i = 0;i < current_depth_size;i++) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left != NULL)q.push(node->left);
        if (node->right != NULL)q.push(node->right);
        v.push_back(node->val);
      }
      ans.push_back(v);
    }
    return ans;
  }
};

