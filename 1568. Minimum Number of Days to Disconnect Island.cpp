class Solution {
public:
    int n,m;
    void Dfs(vector<vector<int>> &grid,int i,int j,vector<vector<bool>> &vis){
        if(i<0||i>=m||j<0||j>=n||vis[i][j]||grid[i][j]==0){
            return;
        }
        vis[i][j]=1;
        Dfs(grid,i+1,j,vis);
        Dfs(grid,i,j+1,vis);
        Dfs(grid,i-1,j,vis);
        Dfs(grid,i,j-1,vis);
    }
    
    int numberOfIslands(vector<vector<int>> &grid){
    int islands = 0;
    vector<vector<bool>> vis(m,vector<bool>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && !vis[i][j]){
                Dfs(grid,i,j,vis);
                islands++;
            }
        }
    }
    return islands;
    } 
    int minDays(vector<vector<int>>& grid) {
       m=grid.size();
       n=grid[0].size();
       int islands = numberOfIslands(grid);
       if( islands>1 || islands==0 ){
        return 0;
       }
       else{ // we have only 1 island 
       //check whether wwe can disconnect the grid in one day
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    islands=numberOfIslands(grid);
                    if(islands==0 || islands>1) return 1;
                    else grid[i][j]=1; //make it land again and go try next cell
                }

            }
        }
       }
       return 2;
    }
};
