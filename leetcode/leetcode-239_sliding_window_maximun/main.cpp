#include <vector>
#include <queue>

// 把每一個數組目前所看到的最大值取出來, 就不需要每次去比對
class MonotonicQueue {
public:
  void push(int e) {
    while(!data_.empty() && e > data_.back()) data_.pop_back();
    data_.push_back(e);
  } 
  
  void pop() {
    data_.pop_front();
  }
  
  int max() const { return data_.front(); }
private:
  std::deque<int> data_;
};
 
class Solution {
public:
  std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    MonotonicQueue q;
    std::vector<int> ans;
        
    for (int i = 0; i < nums.size(); ++i) {
      q.push(nums[i]);
      if (i - k + 1 >= 0) {
        ans.push_back(q.max());
        if (nums[i - k + 1] == q.max()) q.pop();
      }      
    }
    return ans;
  }
};