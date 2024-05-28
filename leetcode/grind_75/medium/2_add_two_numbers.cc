// 第一反應: 先用一個vector紀錄進位資訊, 用recursive進行相加
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// TODO: init的程式碼可能可以精簡到recursive裡面
// TODO: 這傢伙的solution看一下 https://leetcode.com/problems/add-two-numbers/solutions/1340/a-summary-about-how-to-solve-linked-list-problem-c/
class Solution {
public:
  // 不用使用vector, 用一個數字代替就好, 不然進位還要再O(N)一次
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    int init_sum = l1->val + l2->val;
    ListNode* ans = new ListNode();
    if (init_sum >= 10) {
      ans->val = init_sum % 10;
      carry++;
      ListNode* temp = new ListNode(carry);
      ans->next = temp;
    }
    else {
      ans->val = init_sum % 10;
    }

    recursive(l1->next, l2->next, ans, carry);
    return ans;
  }
  void recursive(ListNode* l1, ListNode* l2, ListNode* ans, int carry) {
    if (l1 != nullptr || l2 != nullptr || carry == 1)
    {
      int current_sum = 0;
      if (l1 != nullptr) {
        current_sum += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        current_sum += l2->val;
        l2 = l2->next;
      }

      current_sum += carry;
      carry = current_sum / 10;
      ListNode* node = new ListNode(current_sum % 10);
      ans->next = node;
      ans = ans->next;
      recursive(l1, l2, ans, carry);
    }
  }

};