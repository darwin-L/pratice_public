// 第一反應: 變形背包, 要連續取, 取乘法而非加法, 可能有負值
// 假如這題數列拓展到二維以上, 就不能用指標的形式了
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int ans = nums[0];
    // 能使用左右指針, 因為數列為一維, 當任一方向出現負數, 另一邊有或沒有就很直覺了
    int l_sum = 0, r_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      
      if (l_sum != 0) {
        l_sum *= nums[i];
      }
      else {
        l_sum = 1 * nums[i];
      }
      if (r_sum != 0) {
        r_sum *= nums[nums.size() - 1 - i];

      }
      else {
        r_sum = 1 * nums[i];
      }


      // 總體為-的時候拿ans用, 因為比ans小就一直取ans就可以
      cout << l_sum << " " << r_sum << " " << nums[i] << endl<<endl;
      ans = max(ans, max(l_sum, r_sum));
    }
    return ans;
  }
};
// [-3,-1,-1]