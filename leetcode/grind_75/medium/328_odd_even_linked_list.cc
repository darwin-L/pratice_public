// 第一反應: 遇到奇數位數就設定他的next到nullptr 給下一個奇數, 然後把head給偶數位數
// 最後接在一起
//  must solve the problem in O(1) extra space complexity and O(n) time complexity.
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

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return head;
    ListNode* odd = head;
    ListNode* even = head->next;

    //最後需要接在一起, 所以一開始先拿even的頭, 變數不能直接寫even, 因為even會改變
    ListNode* even_head = head->next;
    // 畫圖一步一步來就可以理解了
    while (odd->next && even->next)
    {
      odd->next = even->next;
      even->next = odd->next->next;

      // 將自身化成next以執行下一次迴圈
      odd = odd->next;
      even = even->next;
    }
    odd->next = even_head;
    return head;

  }
};