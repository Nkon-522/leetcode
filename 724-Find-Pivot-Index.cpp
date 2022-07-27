#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int Tsum = accumulate(nums.begin(),nums.end(),0);
      int lsum = 0;
      for(int i=0;i<nums.size();i++){
        if(Tsum-nums[i]-lsum == lsum){
          return i;
        }
        lsum+=nums[i];
      }
      return -1;
    } 
};

int main(){
  vector<int> nums={1,7,3,6,5,6};
  Solution a;
  cout<<  a.pivotIndex(nums)<<endl;
  return 0;
}
