#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if(prices.size()==1){return 0;}
      int sell = 1;
      int buy = 0;
      int max_profit = 0;
      while(sell < static_cast<int>(prices.size())){
        if(prices[sell] < prices[buy]){
          buy=sell;
        }else if (prices[sell] - prices[buy] > max_profit){
          max_profit = prices[sell] - prices[buy];
        }
        sell++;
      }
      return max_profit;
    }
};

int main(){
  Solution a;
  vector<int> prices = {7,6,4,3,1};
  cout<<a.maxProfit(prices)<<endl;
  return 0;
}
