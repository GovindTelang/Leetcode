class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>> &ans,int  target,int idx,vector<int> &curr){
        if(target<0) return;
        if(target==0) {
            ans.push_back(curr);
            return;}
        for(int i=idx;i<candidates.size();i++){
            if(i>idx /*idx ke liye toh check krenge hi*/ && candidates[i]==candidates[i-1]){
                continue;
            }
            curr.push_back(candidates[i]); //do
            solve(candidates,ans,target-candidates[i],i+1,curr); //explore
            curr.pop_back(); //undo
        }
       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(candidates,ans,target,0,curr);
        return ans;
    }
};
