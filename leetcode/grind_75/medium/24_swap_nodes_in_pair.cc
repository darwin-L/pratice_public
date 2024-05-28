// 第一反應: 
#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    // 因為是兩個兩個換, 所以直接把第二個當頭, 三接在一的尾巴(原本是二), 二接三尾巴
    // 1,2,3 -> 2,1,3
    //先換後面
    ListNode* temp = head->next;
    cout << "b " << temp->val << endl;
    head->next = swapPairs(head->next->next);
    cout << "a " << temp->val << endl;
    temp->next = head;

    return temp;
  }
};