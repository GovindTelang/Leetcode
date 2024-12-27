class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        // space optimization vector<int> maxLeftScore(n);
        int maxLeftScore = values[0];
        int maxScore = 0;
        for(int i=1;i<n;i++){
        int currRightScore = values[i]-i;
        maxScore = max(maxScore,maxLeftScore+currRightScore);
        int currLeftScore = values[i]+i;
        maxLeftScore = max(maxLeftScore,currLeftScore);
        }
        return maxScore;
    }
};
