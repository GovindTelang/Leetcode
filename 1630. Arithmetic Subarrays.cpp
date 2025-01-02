class Solution {
public:
    bool check(vector<int> &arr){
        int n = arr.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        unordered_set<int> st;
        for(int num : arr){
            mini = min(mini,num);
            maxi = max(maxi,num);
            st.insert(num);
        }
        if((maxi-mini)%(n-1)!=0) return 0;
        int diff = (maxi-mini)/(n-1);
        int curr = mini+diff;
        while(curr<maxi){
        if(st.find(curr)==st.end()) return 0;
        curr += diff;
        }
        return 1;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            vector<int> arr(nums.begin()+l[i],nums.begin()+r[i]+1);
            ans.push_back(check(arr));
        }
        return ans;
    }
};
