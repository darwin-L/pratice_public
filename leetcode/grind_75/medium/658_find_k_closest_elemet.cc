// 第一反應: 設定一個k長度的陣列裡面儲存差額以及原始的位置, 然後遍歷arr的時候一個一個去比較, 最後sort arr
// 但這樣時間複雜度會很差, 因為每次查找還要遍歷k次陣列
#include<bits/stdc++.h>
using namespace std;
// 因為input的陣列已經排序過所以
// 可以把這題拆成兩個問題-> k: 決定靠近x點的陣列長度為多少. 因為有|a - x| == |b - x| and a < b這個條件, 所以用k算右邊終點
//  x: 計算絕對值差額 (左邊起點)
class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0;
    // k起始的時候要offset k個, 因為迴圈會拿k當變數
    int right = arr.size() - k;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (x - arr[mid] > arr[mid + k] - x)
        left = mid + 1;
      else
        right = mid;
    }
    // 最後記得offset回來
    return vector<int>(arr.begin() + left, arr.begin() + left + k);
  }
};