// https://leetcode.com/problems/merge-two-sorted-lists/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL)    return list2;
    if (list2 == NULL)    return list1;

    // init first head node
    ListNode* ptr = list1;
    if (list1->val < list2->val)
    {
      list1 = list1->next;
    }
    else {
      ptr = list2;
      list2 = list2->next;
    }
    // use curr to link all remain node
    ListNode* curr = ptr;

    // iterator two list
    // use && not || to avoid possible null pointer
    while (list1 && list2)
    {
      if (list1->val < list2->val) {
        curr->next = list1;
        list1 = list1->next;
      }
      else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;

    }

    // clean last list, no matter which is bigger
    if (!list1) curr->next = list2;
    if (!list2) curr->next = list1;
    return ptr;

  };

};