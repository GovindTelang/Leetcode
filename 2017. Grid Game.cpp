class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
       long long firstRowRemain = accumulate(grid[0].begin(),grid[0].end(),0LL);
       long long secondRowRemain = 0;
       long long ans = LONG_LONG_MAX;
       for(int i=0;i<grid[0].size();i++){     //note grid[0].size() not grid.size()
        firstRowRemain -= grid[0][i];    
        ans = min(ans,max(firstRowRemain,secondRowRemain));
        secondRowRemain += grid[1][i];
       }
       return ans;
    }
};
