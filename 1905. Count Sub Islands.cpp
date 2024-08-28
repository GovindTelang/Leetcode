class Solution {
public:
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    bool checkSubIsland(vector<vector<int>> &grid1,vector<vector<int>> &grid2,int i,int j){
        int m = grid1.size();
        int n = grid1[0].size();

        bool result = 1; //idhar return nhi kr rhe as subisland nhi bhi ho toh bhi visit toh krna padega pure island ko taki visited (-1) mark kr paae

        queue<pair<int,int>> q; // {i,j} //bfs we use queue
        q.push({i,j});
        grid2[i][j] = -1; // mark visited

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            if(grid1[x][y] != 1){ //grid1 must have 1 at that same coordinate
                result = 0;
            }

            for(vector<int> &d : dir){
                int newX = x + d[0];
                int newY = y + d[1];

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid2[newX][newY]==1){
                    grid2[newX][newY]=-1;
                    q.push({newX,newY});
                }
            }
        }
        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
      int subIslands = 0;
      int m = grid2.size();
      int n = grid2[0].size();

      for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(grid2[i][j]==1 && checkSubIsland(grid1,grid2,i,j)){
        subIslands++;
        }
      }
      }  
      return subIslands;
    }
};
