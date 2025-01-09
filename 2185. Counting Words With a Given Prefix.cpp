class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
      int res = 0;
      for(string word : words){
        if(word.size()<pref.size()) continue;
        if(word.find(pref)==0) res++;
      }
      return res;  
    }
};
