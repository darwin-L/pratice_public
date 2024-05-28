#include <bits/stdc++.h>
using namespace std;

// 主要是確認 Amortized_analysis的觀念, 但這個手法並不是太大眾並且計算複雜度的過程個人認為非常不嚴謹
class MyQueue {
  stack<int> input, output;
public:
  MyQueue() {

  }

  void push(int x) {
    if (input.size() == 0) {
      input.push(x);
      return;
    }
    int data;
    data = input.top();
    input.pop();
    this->push(x);
    input.push(data);
    return;
  }
  int pop() {
    int _ = input.top();
    input.pop();
    return _;
  }

  int peek() {
    return input.top();
  }

  bool empty() {
    return input.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */