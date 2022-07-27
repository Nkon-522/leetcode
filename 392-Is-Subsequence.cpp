#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
      int c = 0;
      for(auto letra:t){
        if(letra == s[c]){
          c++;
        }
      }
      if(c==static_cast<int>(s.size())){return true;}
      return false;
    }
};

int main(){
  Solution a;
  cout<<a.isSubsequence("","")<<endl;

}
