// 第一反應: 原本想的是先跑到尾巴紀錄長度然後到n的時候在踢掉目標, 但這時間複雜度不符合題意
#include<bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;

    // 先跑到n
    for (int i = 0; i < n; i++) fast = fast->next;

    // 從頭先跑到目標, 如果跑不完代表n等於陣列本身. e.g. [1]
    if (!fast) return head->next;

    // 再跑到底, 因為這樣fast跟slow會差n
    while (fast->next)
    {
      fast = fast->next;
      slow = slow->next;
    }

    // 根據題目要求slow直接跳過下一個元素
    slow->next = slow->next->next;
    return head;

  }
};