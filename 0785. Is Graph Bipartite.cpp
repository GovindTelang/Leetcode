class Solution {
public:
    bool dfs(int start,int col,vector<vector<int>> &graph,int color[]){
    color[start]=col;
    for(auto it : graph[start]){
        if(color[it]==-1){
            if(dfs(it,!col,graph,color)==false) return false;
        }
        else if(color[it]==col) return false;
    }
    return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
       /* vector<int> adjLs[n];    
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }*/
        int color[n];
        for(int i=0;i<n;i++) color[i]=-1;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,0,graph,color)) return false;
            }
        }
        return true;
    }
};
