// 不能修改陣列, Space O(1), 大概是xor 跟136.find_single_number有點像
#include<bits/stdc++.h>
using namespace std;
// 但xor不能用, 因為xor跟total沒有相關, 而且重複的元素會出現兩次以上
// 169_majorityElement 的counting也不能用, 因為元素沒有超過一半
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    // 善用這個限制:  containing n + 1 integers where each integer is in the range [1, n] inclusive.
    if (nums.size() > 1) {
      int slow = nums[0];
      int fast = nums[nums[0]];
      while (slow != fast)
      {
        slow = nums[slow];
        fast = nums[nums[fast]];
      }

      fast = 0;
      while (slow != fast)
      {
        slow = nums[slow];
        fast = nums[fast];
      }
      return slow;
    
    }
    return -1;
  }
};
