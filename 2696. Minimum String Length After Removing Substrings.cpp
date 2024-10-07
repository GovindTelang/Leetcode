class Solution {
public:
    int minLength(string s) {
      vector<char> vec;
      vec.push_back(s[0]);
      for(int i=1;i<s.size();i++){
      if(!vec.empty() && ((vec.back()=='A' && s[i]=='B') || (vec.back()=='C' && s[i]=='D'))){
      vec.pop_back();
      }
      else vec.push_back(s[i]);
      }   
      return vec.size();
    }
};
