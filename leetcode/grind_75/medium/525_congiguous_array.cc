// 看到一維連續子陣列, 用左右index, 但因為只有01且回傳長度取左邊開始就好
// 並且由於vector的重新賦值低效, 用map以及i來判斷目前長度
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    if (nums.size() == 2 && nums[0] != nums[1]) return 2;

    unordered_map<int, int> tabu;
    tabu[0] = -1;

    // map把數列張開 1跟0之間的寬度就是差額
    int counting_current_element = 0;
    int current_length = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        counting_current_element++;
      }
      else {
        counting_current_element--;
      }

      if (tabu.count(counting_current_element) > 0) {
        current_length = max(current_length, i - tabu[counting_current_element]);
      }
      else {
        tabu[counting_current_element] = i;
      }

    }

    return current_length;
  }
};