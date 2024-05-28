//  Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
// 第一反應: 幹怎麼可能. 可能要用merge-sort 但不確定怎麼實做在linked-list上面
// [-1,5,3,4,0] 奇數個的話要再想一下
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

/**
 * Merge sort use bottom-up policy,
 * so Space Complexity is O(1)
 * Time Complexity is O(NlgN)
 * stable sort
*/
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (!head || !(head->next)) return head;

    //get the linked list's depth
    ListNode* cur = head;
    int depth = 0;
    while (cur) {
      depth++;
      cur = cur->next;
    }

    ListNode dummy(0);
    dummy.next = head;
    ListNode* left, * right, * tail;
    // divieded steps by log2(n)
    for (int step = 1; step < depth; step <<= 1) {
      // 把tail和dummy連在一起, tail拿來放該次迭代的尾端(相同於dummy)
      // cout<<step<<endl;
      cur = dummy.next;
      tail = &dummy;
      // 迴圈控制該次迭代的深度跟左右子問題的寬度, cur除了判斷寬度之外還有把奇數的元素放到右邊去給後面merge
      cout << endl;
      while (cur) {
        left = cur;
        right = split(left, step);
        cur = split(right, step);
        tail = merge(left, right, tail);
      }
    }
    return dummy.next;
  }
private:
  /**
   * Divide the linked list into two lists,
   * while the first list contains first n ndoes
   * return the second list's head
   */
  ListNode* split(ListNode* head, int n) {
    for (int i = 1; i < n; i++) {
      if (head == nullptr) break;
      head = head->next;
    }

    if (!head) return NULL;
    ListNode* second = head->next;
    head->next = NULL;
    return second;
  }
  /**
    * merge the two sorted linked list l1 and l2,
    * then append the merged sorted linked list to the node head
    * return the tail of the merged sorted linked list
   */
  ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head) {
    ListNode* cur = head;
    cout << head->val << " ";
    // 每一次合併都要檢查兩個陣列(串列)是否還有元素並比較
    while (l1 && l2) {
      if (l1->val > l2->val) {
        cur->next = l2;
        cur = l2;
        l2 = l2->next;
      }
      else {
        cur->next = l1;
        cur = l1;
        l1 = l1->next;
      }
    }
    cur->next = (l1 ? l1 : l2);

    // 把該次剩下的排序好的元素(可能有超過一個)接進去. e.g. [4,19,14,5,-3,1,8,5,11,15]
    while (cur->next) {
      cur = cur->next;
    }
    return cur;
  }
};