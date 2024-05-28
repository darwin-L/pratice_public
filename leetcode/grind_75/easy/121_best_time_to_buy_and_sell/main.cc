// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// 第一個反應是做兩個list然後sort, 然後最小值的那一天減去最大值的那一天, 但這樣複雜度似乎不夠好
// 因為知道陣列大小, 並且要照陣列的順序(這把複雜度壓到一維, 並且有子集的交集) 所以可以用貪心的方式去抓最大價值的那一個set
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/ 這是困難版本
#include<vector>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int maxValue = 0;
    int minBuyValue = 1e9;
    for (int i = 0; i < prices.size() - 1; i++) {
      if (prices[i] < minBuyValue) minBuyValue = prices[i];
      int temp = prices[i + 1] - minBuyValue;
      if (temp > maxValue) maxValue = temp;
    }
    return maxValue;
  }

  // 如果不使用最小購買值來當變數而是使用子集來當作變數的作法
  int maxProfit(vector<int>& prices) {
    int maxSubSet = 0;
    int maxSet = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
      maxSubSet += prices[i + 1] - prices[i];
      // 如果子集總和小於0則捨棄該子集
      if (maxSubSet > 0) {
        maxSubSet = maxSubSet;
      }
      else {
        maxSubSet = 0;
      }
      maxSet = max(maxSubSet, maxSet);
    }
    return maxSet;
  }
};