// unordered_map去做, 後面的string也要做成unordered_map, 因為name跟email都要能夠關聯
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
  unordered_map<string, int> name_with_id;
  unordered_map<string, int> email_with_id;
  vector<vector<string>> ans;
public:
// TODO: 沒很難再試一下
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int global_id2 = 0;
    for (int i = 0; i < accounts.size(); i++) {
      for (int j = 0; j < accounts[i].size(); j++) {
        cout << accounts[i][j] << " ";
        int current = global_id2;
        if (j == 0) {
          if (name_with_id.find(accounts[i][0]) == name_with_id.end()) {
            name_with_id.insert(make_pair<string,int>(accounts[i][0], global_id2));
            global_id2++;
          }
        }
        if (email_with_id.find(accounts[i][j]) == email_with_id.end()) {
          current = email_with_id.find(accounts[i][j])->second;
        }
        email_with_id.insert({accounts[i][j], current});
      }
    }
    return ans;
  }
};