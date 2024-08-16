class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        for(int i=1;i<arrays.size();i++){
            ans = max(ans,max(abs(maxVal-arrays[i][0]),abs(minVal-arrays[i].back())));
            //idhar seedhe pure elements ka min nikal kar aur pure elements ka sabse max element nikal kar abs(max-min) isliye nhi kr rhe as You can pick up two integers from two different arrays (each array picks one) and calculate the distance as given in question
            minVal = min(minVal,arrays[i][0]);
            maxVal = max(maxVal,arrays[i].back());
        }
        return ans;
    }
};
