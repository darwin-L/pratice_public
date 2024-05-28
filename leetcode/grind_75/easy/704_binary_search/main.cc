// 這個如果創建樹的時候已經做好結構, 查詢複雜度就直接是O(ln), 但題目給的是vector, 
// 如果照著前+後/2來判斷目標的程式,在coner-case像是:[1,2,3,4,5,6,7,8,9,10 ...] 找1可能效率會比較差
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int upper = nums.size() - 1;
    int lower = 0;
    while (lower <= upper)
    {
      
      int mid = lower + ((upper - lower) / 2);
      if (nums[mid] == target) {
        return mid;
      }
      // -1是為了避免跳不出迴圈
      if (target < nums[mid]) {
        upper = mid - 1;
      }
      else {
        lower = mid + 1;
      }
    }


    return -1;


  }
};