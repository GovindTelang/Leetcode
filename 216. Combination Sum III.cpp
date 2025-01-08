class Solution {
public:
    void help(vector<vector<int>> &sol,vector<int> &curr,int k,int n,int i){
        
        if(curr.size()==k){
            if(n==0){
                sol.push_back(curr);
            }
            return;
        }
        if(i>=10) return;
    //  if(n<0 || curr.size()>k) return;
        if(n-i >= 0){
            curr.push_back(i);
            help(sol,curr,k,n-i,i+1);
            curr.pop_back();
        }
        help(sol,curr,k,n,i+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> sol;
        vector<int> curr;
        help(sol,curr,k,n,1);
        return sol;
    }
};
/*
This solution beats 100 percent solutions
*/
