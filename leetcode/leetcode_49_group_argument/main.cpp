#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<iostream>

class Solution {
public:
  Solution(){

  }
  ~Solution(){

  }
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> ans;
    std::unordered_map<std::string, std::vector<int>> m;
 
    for (int i = 0; i < strs.size(); ++i) {
      std::string c = strs[i];
      std::cout << c << std::endl;
      // TODO: maybe use the char to pervnet sort all string, if string is too long it will be inefficient
      std::sort(begin(c), end(c));
      m[c].push_back(i);
    }
 
    for (const auto& kv : m) {
      ans.push_back({});
      for (int i : kv.second)
        ans.back().push_back(strs[i]);    
    }
 
    return ans;
  }
};
int main (void){
  std::vector<std::string> input = {"eat","tea","tan","ate","nat","bat"};
  Solution *ans = new Solution();
  std::vector<std::vector<std::string>> answer = ans->groupAnagrams(input);
  std::cout<<"-----answer----"<<std::endl;
  for (int i = 0; i<answer.size(); i++) {
    for (int j = 0; j<answer[i].size(); j++) {
      std::cout << answer[i][j];
      std::cout<<' ';
    }
    std::cout<<' '<<std::endl;
  }
  return 0;
}