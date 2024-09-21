class Solution {
public:
    void solve(int n,int curr,vector<int> &ans){
        if(curr > n){
            return;
        }
        ans.push_back(curr);

        for(int append=0;append<=9;append++){
            int new_num = curr*10 + append;
            if(new_num > n){
            return;
            } 
            solve(n,new_num,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
      vector<int> ans;
      for(int i=1;i<=9;i++){
        solve(n,i,ans);
      }
      return ans;  
    }
};
