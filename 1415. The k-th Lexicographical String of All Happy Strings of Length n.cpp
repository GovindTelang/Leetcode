class Solution {
public:
    void backk(int n,int k,vector<string> &ans,string &curr,vector<char> &v){
        if(ans.size()==k) return;
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<3;i++){
            if(curr.size() == 0 || curr.back() != v[i]){
                curr.push_back(v[i]);
                backk(n,k,ans,curr,v);
                curr.pop_back();
            }
            
        }
    }
    string getHappyString(int n, int k) {
     vector<string> ans;
     vector<char> v{'a','b','c'};
     string curr = "";
     backk(n,k,ans,curr,v);
     return ans.size()<k ? "" : ans[k-1];   
    }
};
