// 第一反應: O(n log(k)) time and O(n) extra space. map<string,int>,
//  但map不能照value排所以用vector<pair<string,int>>


#include<bits/stdc++.h>
using namespace std;
typedef priority_queue <
  pair<string, int>,
  vector<pair<string, int>>,
  decltype([](const pair<string, int>& a, const pair<string, int>& b) {
  return a.second > b.second || (a.second == b.second && a.first < b.first);
    })
  > custom_priority_queue;
    // 難點在資料結構, 以及其方法
    // priority_queue, emplace, decltype
    class Solution {
    public:
      vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (auto w : words) freq[w]++;


        custom_priority_queue  pq;

        for (auto w : freq) {
          pq.emplace(w.first, w.second);
          if (pq.size() > k) pq.pop();
        }

        vector<string> ans(k + 1);
        int idx = k;
        while (idx > 0)
        {
          ans[idx] = pq.top().first;
          idx--;
          pq.pop();
        }
        ans.erase(ans.begin());
        return ans;

      }
    };