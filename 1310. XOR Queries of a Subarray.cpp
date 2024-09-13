class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
       vector<int> ans;
       int n = arr.size();
       vector<int> res(n,0);
       res[0]=arr[0];
       for(int i=1;i<n;i++){
        res[i]=res[i-1]^arr[i];
       }
       for(auto q : queries){
        int left = q[0];
        int right = q[1];
        int required = res[right]^(left == 0 ? 0 : res[left-1]); //left-1 tak ke elements ka asar hatane ke liye
        ans.push_back(required);
       }
       return ans; 
    }
};
