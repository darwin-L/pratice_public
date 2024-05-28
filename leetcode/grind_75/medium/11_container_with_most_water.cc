// 第一反應: dp題 計算每一個包起來的面積然後比較目前的長度與最大面積的差別,
// 因為只要抓最大的所以不用儲存所有的結果,
// 但dp的話時間複雜度太差(O(N!)) 
// 題目設計是整數規劃, 所以能從左右開始抓即可(長度最大->最小), 就可以只看高度
// 但如果長度的變量是小數, 題目演變成線性規劃, 問題複雜度就會差很多, 得使用dp然後去降低時間複雜的
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int curr_max = 0;
    // 不用相等因為相等的話面積為0
    while (left < right)
    {
      int current = min(height[left], height[right]) * (right - left);
      if (current > curr_max)  curr_max = current;
      if (height[left] < height[right]) {
        left++;
      }
      else {
        right++;
      }
    }
    return curr_max;
  }
};