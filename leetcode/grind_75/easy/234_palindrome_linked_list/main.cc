#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// 時間複雜度個人覺得是O(2N)而不是O(n), 總之解法就是類似兩個pointer分別從頭尾接近, 但因為這題是單向linked-list所以要先做預處理
class  Solution {
  ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr != NULL)
    {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* rev = reverse(slow);

    while (rev != NULL)
    {
      if (head->val != rev->val) return false;
      head = head->next;
      rev = rev->next;
    }
    return true;
  }
};