// 第一反應: 用unordered_map去做<char, int> 紀錄input列表
// cpu_lock設計成 一個計數器= n, 當次冷卻之前所執行的任務<set> 當計數器為0重置任務
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 這邊不是用重置的而是算出最小步數之後再加上去
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> input_as_map;
        int count = 0;
        for(auto ele: tasks) {
          input_as_map[ele]++;
          count = max(count,input_as_map[ele]);
        }
        // 用最小需要的步數去加上個數
        int ans = (count - 1) * (n+1);

        // 處理case: 如果有不同元素有相同的出現次數
        for(auto ele: input_as_map) {
          if(ele.second == count) ans++;
        }
        // 處理case: 所有人個數都為1
        ans = max(ans,int(tasks.size()));
        return ans;
    }
};
// TODO:用自己的寫法試試