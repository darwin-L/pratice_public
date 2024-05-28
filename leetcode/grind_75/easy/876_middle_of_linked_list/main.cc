// 第一反應: 用vector iterator push 找到長度之後, 用中間那個 時間複雜O(n) 空間O(2n)
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // 因為fast 一次兩格, 得確認自身以及下一步是否是null, 不然會有nullptr
        while(fast && fast -> next) 
            slow = slow -> next,                                  // slow moves at 1 node / iteration
            fast = fast -> next -> next;                          // fast moves 2 nodes / iteration
        return slow;                                              // slow ends up at mid
    }
};