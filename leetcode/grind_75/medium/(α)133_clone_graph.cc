// 第一反應: 無
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// unorder_map 的find會給出該node的iterator
// unorder_map 的end會從最後跑到最前面, 可以利用這個特性去拜訪所有的鄰居
// Returns an iterator pointing to the past-the-end element in the unordered_map container (1) or in one of its buckets (2).
class Solution {
public:
  Node* cloneGraph(Node* node) {
    if (!node) {
      return nullptr;
    }
    // if (_copies.count(node) == 0) 與下面等價, 因為沒有neighbor的會成為0
    if (_copies.find(node) == _copies.end()) {
      _copies[node] = new Node(node->val, {});
      for (Node* neighbor : node->neighbors) {
        _copies[node]->neighbors.push_back(this->cloneGraph(neighbor));
      }
      cout << "linked " << node->val << endl;
    }
    cout << "pass " << node->val << endl;
    return _copies[node];
  }
private:
  unordered_map<Node*, Node*> _copies;
};

// 這個比較直覺, 每次neighbor有東西就直接推入queue然後從queue裡面往外推
class Solution_DFS {
public:
  Node* cloneGraph(Node* node) {
    if (!node) {
      return NULL;
    }
    Node* copy = new Node(node->val, {});
    copies[node] = copy;
    queue<Node*> todo;
    todo.push(node);
    while (!todo.empty()) {
      Node* cur = todo.front();
      todo.pop();
      for (Node* neighbor : cur->neighbors) {
        if (copies.find(neighbor) == copies.end()) {
          copies[neighbor] = new Node(neighbor->val, {});
          todo.push(neighbor);
        }
        copies[cur]->neighbors.push_back(copies[neighbor]);
      }
    }
    return copy;
  }
private:
  unordered_map<Node*, Node*> copies;
};