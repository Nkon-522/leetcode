#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>
using namespace std;

class Solution{
  public:
    vector<int> runningSum(vector<int>& nums);
};

vector<int> Solution::runningSum(vector<int>& nums){
  //vector<int> res(nums.size());
  //std::partial_sum(nums.begin(), nums.end(), res.begin());
  
  std::partial_sum(nums.begin(), nums.end(), nums.begin());
  return nums;
//  std::partial_sum(nums.begin(), nums.end(), nums.begin());
  //return res;
}


int main(){
  Solution a;
  vector<int> nums = {1,2,3,4,5};
  auto res =  a.runningSum(nums);
  for(auto& x:res){
    cout<<x<<" ";
  }
  cout<<endl;
  return 0;
}
