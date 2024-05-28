#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> vec(nums.size());
    int left = 0, right = nums.size() - 1;
    // 因為原本的序列就是從小到大, 如果底下的迴圈要從0(最小)開始建立的話反而會很麻煩
    // 想像是一個平面上面有數列, 絕對值可以把數列的負數部份反折到正數, 所以從右往左掃描比較容易寫
    for (int k = nums.size() - 1; k >= 0; k--) {
      if (abs(nums[right]) > abs(nums[left])) {
        vec[k] = nums[right] * nums[right];
        right--;
      }
      else {
        vec[k] = nums[left] * nums[left];
        left++;
      }
    }
    return vec;
  }
};












