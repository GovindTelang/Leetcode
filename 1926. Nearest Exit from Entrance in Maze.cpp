class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        int moves = 1;  //if you start from moves=0 it will give errors as aap last main nhi pehle hi moves return kar rhe ho
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x,y] = q.front();
                q.pop();
                for(auto [i,j]:dir){
                    int new_x = x+i;
                    int new_y = y+j;
                    if(new_x<m && new_x>=0 && new_y<n && new_y>=0 && maze[new_x][new_y]!='+'){
                       if((new_x==m-1 || new_y==n-1 || new_x==0 || new_y==0)){
                        if(!(new_x==entrance[0] && new_y==entrance[1])){  // very beautiful and compact way of writing this logic
                            return moves;
                        }
                       } 
                    maze[new_x][new_y]='+';
                    q.push({new_x,new_y});   
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
