// 如果從頭走到尾, 發現next有重複就是有cycle
// 但如果限制成O(1)的話要用兩個pointer令一個比較晚出發, 當其中一個追上時, 就是有cycle, 但時間複雜度會變得不固定, 會變得很看測資
// e.g. 如果一個最尾端才有cycle的資料, 步長差額為1的追法會讓複雜度接近O(n)
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode* head) {
    ListNode* runner = head;
    ListNode* chaser = head;

    // 用比較快的步長作為迴圈跳句因為可以更快的跳出, 且不用處理null pointer的例外
    while (chaser != NULL && chaser->next != NULL)
    {

      runner = runner->next;
      chaser = chaser->next->next;
      if (chaser == runner) return true;
    }
    return false;
  }
};