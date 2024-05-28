
#include<iostream>
#include<queue>
#include<vector>
// using namespace std;
class Solution {
    #define p pair<int,int>
public:
    int findMaximizedCapital(int k, int W, std::vector<int>& Profits, std::vector<int>& Capital) {
        std::priority_queue<int> maxHeapProfit; // max heap on profit
        std::priority_queue< std::p, std::vector<std::p>, std::greater<std::p> > minHeapOnCapital; // min heap on capital
        for( int i=0; i < Profits.size(); i++ ) {
            minHeapOnCapital.push( std::make_pair( Capital[i], Profits[i] ) );
        }
        
        int profit = W;
        while( k ) {
            while( !minHeapOnCapital.empty() && profit >= minHeapOnCapital.top().first ) {
                maxHeapProfit.push( minHeapOnCapital.top().second );
                minHeapOnCapital.pop();
            }  
            if( maxHeapProfit.empty() ) break;
          
            k--;
            profit += maxHeapProfit.top();
            maxHeapProfit.pop(); 
        }
        return profit;
    }
};

int main(){
    Solution *a = new Solution;
    std::vector<int> profit{1,2,3}; 
    std::vector<int> capital{0,1,2};
    // profit.assign(1,2,3)
    std::cout<<a->findMaximizedCapital(3,0,profit,capital);
}