class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       int n = strs.size();
       if(n==0) return "";
       string prefix = strs[0];
       for(int i=1;i<n;i++){
        int j=0;
        while(j<prefix.size() && j<strs[i].size() && prefix[j]==strs[i][j]){
            j++;
        }
        prefix = prefix.substr(0,j);
        if(prefix.size()==0) return "";
       }
        return prefix;
    }
};
