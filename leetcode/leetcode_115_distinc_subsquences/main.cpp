#include <vector>
#include <string>
#include <iostream>
using namespace std;

//   Ø r a b b b i t
// Ø 1 1 1 1 1 1 1 1
// r 0 1 1 1 1 1 1 1
// a 0 0 1 1 1 1 1 1
// b 0 0 0 1 2 3 3 3
// b 0 0 0 0 1 3 3 3
// i 0 0 0 0 0 0 3 3
// t 0 0 0 0 0 0 0 3 
class Solution {
public:
    int numDistinct(string s, string t) {
      if(t.size() > s.size()) return 0;
      if(t.size()== s.size()) return s==t;
      vector <long> dp(t.size()+1,0);  
      dp[0] = 1;
      for(int i = 0; i < s.size(); ++i){
        for(int j =(t.size())-1; j>=0; --j){
          //dp[j] means number of subsequence that has matched j char in t, need to compare with t[j]
          if(t[j]==s[i]){
            dp[j+1] += dp[j];//use this character, so dp[j+1] should be modified
            //at the same time keep dp[j] unchanged, which means skip this character
          }
        }  
      }
      return dp.back();
    }
};
int main(void){
    Solution s = Solution();
    std::cout<<s.numDistinct("rabbbit","rabbit")<<std::endl;
    std::cout<<s.numDistinct("babgbag","bag")<<std::endl;
    return 0;
}