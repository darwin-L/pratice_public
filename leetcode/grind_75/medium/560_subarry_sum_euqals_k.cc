// 第一反應: dp題, 用vector把之前所儲存過的子串列存下來. 複雜度不夠好
#include<bits/stdc++.h>
using namespace std;
// O(N)time
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> map;

    int sum = 0, result = 0;
    // 因為0算一次. e.g. [5,0,0] k = 5 -> 3
    map[sum] = 1;

    //TODO: 再想一次
    for (int ele : nums) {
      sum += ele;
      result += map[sum - k];
      map[sum]++;
    }

    return result;
  }
};

// using dp, less memory , LOTs of time
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        vector<int> prefixsum(nums.size());
        prefixsum[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
            prefixsum[i] = nums[i] + prefixsum[i-1];
        
        for(int i=0; i<nums.size(); i++) {
            int sum = 0;
            int sub = 0;
            if(i > 0)
                sub = prefixsum[i-1];
            for(int j=i; j<nums.size(); j++) {
                sum = prefixsum[j] - sub;
                if(sum == k)
                    res++;
            }
        }

        return res;
    }
};