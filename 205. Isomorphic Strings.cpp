class Solution {
public:
    bool isIsomorphic(string s, string t) {
      if(s.size()!=t.size()) return false;
      unordered_map<char,char> MapST,MapTS;
      for(int i=0;i<s.size();i++){
        char c = s[i];
        char d = t[i];

        if((MapST.count(c)!=0 && MapST[c]!=d) || (MapTS.count(d)!=0 && MapTS[d]!=c)) return false; 
        MapST[c]=d;
        MapTS[d]=c;
      }  
      return true;
    }
};
