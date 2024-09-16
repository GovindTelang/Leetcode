class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int maxi = 0;
        int n = timePoints.size();
        vector<int> ans;
        for(string st : timePoints){
            int hour = (st[0]-'0')*10 + (st[1]-'0');
            int minute = (st[3]-'0')*10 + (st[4]-'0');
            int res = hour*60+minute;
            ans.push_back(res);
        }
        sort(ans.begin(),ans.end());
        int mini = INT_MAX;
        for(int i=1;i<n;i++){
            mini = min(mini,abs(ans[i]-ans[i-1]));
        }
        return min(mini,1440-ans[n-1]+ans[0]);
    }
};
