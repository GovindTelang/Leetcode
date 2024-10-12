class Solution {
public:
    
    int minGroups(vector<vector<int>>& intervals) {
       vector<int>arr,dep;
        int n=intervals.size();
        for(auto x:intervals){
            arr.push_back(x[0]);
            dep.push_back(x[1]);
        }
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i = 1, count = 1;
        int j = 0, ans = 1;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j]) // one more platform needed
            {
                count++;
                i++;
            }
            else // one platform can be reduced
            {
                count--;
                j++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
