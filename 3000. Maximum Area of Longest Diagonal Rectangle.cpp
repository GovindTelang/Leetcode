class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int maxo = 0;
        for(vector<int> &au : dimensions){
            if(au[0]*au[0] + au[1]*au[1] > maxo){
                maxo = au[0]*au[0] + au[1]*au[1];
                ans = au[0]*au[1];
            }
            else if(au[0]*au[0] + au[1]*au[1] == maxo){
                ans = (ans > au[0]*au[1]) ? ans : au[0]*au[1];
            }
        }
        return ans;
    }
};
