#include <iostream>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char, char> m_s;
      unordered_map<char, char> m_t;
      for(int i=0; i<static_cast<int>(s.size());i++){
        if(m_s.find(s[i]) == m_s.end() && m_t.find(t[i]) == m_t.end()){
          m_s.insert({s[i],t[i]});
          m_t.insert({t[i],s[i]});
        }else if(m_s[s[i]] != t[i] || m_t[t[i]] != s[i]){
          return false;
        }
      }
      return true;
    }
};

int main(){
  Solution a;
  cout<<a.isIsomorphic("bar","foo")<<endl;
}
