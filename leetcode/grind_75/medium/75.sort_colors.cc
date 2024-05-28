// 條件:不能用sort, 要用常數空間
// 第一反應: length不長, 2最後用結果的長度比, 1直接加起來就是個數, 0直接推
// NOTE: 可以用offset做
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
      vector<int> ans;
      int one_count = 0;
      for(int i = 0; i <nums.size(); i++) {
        if(nums[i] == 0) ans.push_back(0);
        if(nums[i] == 1) one_count++;
      }
      for(int i = 0; i<one_count; i++) {
        ans.push_back(1);
      }
      const int lefted_two = nums.size() - ans.size();
      for(int i = 0; i < lefted_two; i++) {
        ans.push_back(2);
      }
      nums = ans;
    }
};