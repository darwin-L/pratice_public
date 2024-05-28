// 第一反應: 當總價值小於0的時候捨棄前面的加總, 並將該結果儲存為目前最大值
#include<vector>
using namespace std;
class Solution {
public:
  //Kadane's algorithms 直接取目前最大的那個序列就可以了
  int maxSubArray(vector<int>& nums) {
    int current_max = 0;
    int global_max = -1e9;
    for (auto ele : nums) {
      current_max = max(ele, current_max + ele);
      global_max = max(global_max, current_max);
    }
    return global_max;
  }
};

class Solution_Divide_and_Conqure {
public:
  vector<int> left, right;
  int maxSubArray(vector<int>& nums) {
    left = right = nums;
    for (int i = 1; i < size(nums); i++)  left[i] += max(0, left[i - 1]);
    for (int i = size(nums) - 2; ~i; i--)   right[i] += max(0, right[i + 1]);
    return maxSubArray(nums, 0, size(nums) - 1);
  }
  int maxSubArray(vector<int>& A, int L, int R) {
    if (L == R) return A[L];
    int mid = L + (R - L) / 2;
    return max({ maxSubArray(A, L, mid), maxSubArray(A, mid + 1, R), left[mid] + right[mid + 1] });
  }
};

// 製表, 空間複雜度差一點O(N), 時間複雜度差一點2O(n)
class Solution_Tabulation {
public:
  int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums);
    for (int i = 1; i < size(nums); i++)
      dp[i] = max(nums[i], nums[i] + dp[i - 1]);
    return *max_element(dp.begin(), dp.end());
  }
};