class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
     int n = grid.size();
     vector<int> maxR(n,0),maxC(n,0);
     int gov = 0;
     for(int i=0;i<n;i++){
       maxR[i] = *max_element(grid[i].begin(),grid[i].end());
       for(int j=0;j<n;j++){
        maxC[j] = max(maxC[j],grid[i][j]);
       }
     }
     cout<<maxR[0]<<maxC[0];
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            gov += min(maxR[j],maxC[i])-grid[i][j];
        }
     }
     return gov;
    }
};
