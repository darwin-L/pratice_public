// 第一反應: 用map紀錄每個元素出現的次數然後抓前面k個
// 跟nth_elements一樣, 但不能用任何sorting的函式庫
// 我認為不能使用任何stl包含sorting的資料結構 e.g. priority_queue, set(multiset), partial_sort
// 題目的難點在於自建資料結構 worst case的時候(最後k個才是最大的), 如果不使用map會造成時間複雜度的大幅增加
#include<bits/stdc++.h>
using namespace std;
// https://medium.com/@ralph-tech/%E6%BC%94%E7%AE%97%E6%B3%95%E5%AD%B8%E7%BF%92%E7%AD%86%E8%A8%98-%E5%A0%86%E7%A9%8D%E6%8E%92%E5%BA%8F-heap-sort-4a4f6d48482e
// 可以參考這個
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    // heap tree基本上只處理最接近自己的三個節點
    buildMaxHeap(nums);
    // 所以最後還是要sort
    for (int i = 0; i < k - 1; i++) {
      this->heapSize--;
      swap(nums[0], nums[this->heapSize]);
      maxHeapify(nums, 0);
    }
    // for(auto ele: nums) {
    //   cout<<ele<<" ";
    // }

    return nums[0];
  }
private:
  int heapSize;

  int left(int i) {
    return (i << 1) + 1;
  }

  int right(int i) {
    return (i << 1) + 2;
  }
  // max_heap 是根節點一定比子節點大
  void maxHeapify(vector<int>& nums, int i) {
    int largest = i, l = left(i), r = right(i);
    if (l < heapSize && nums[l] > nums[largest]) {
      largest = l;
    }
    if (r < heapSize && nums[r] > nums[largest]) {
      largest = r;
    }
    if (largest != i) {
      swap(nums[i], nums[largest]);
      maxHeapify(nums, largest);
    }
  }

  void buildMaxHeap(vector<int>& nums) {
    heapSize = nums.size();
    for (int i = (heapSize >> 1) - 1; i >= 0; i--) {
      maxHeapify(nums, i);
    }
  }
};