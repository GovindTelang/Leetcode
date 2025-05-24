class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
     vector<int> ans;
     string an = "";
     for(int i=0;i<words.size();i++){
        string y = words[i];
        if(y.find(x)!=string::npos) ans.push_back(i);
     }
     return ans;   
    }
};
