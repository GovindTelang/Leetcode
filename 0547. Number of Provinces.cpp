class Solution {
public:
    void dfs(vector<int> adjLs[],vector<bool> &vis,int start){
        vis[start]=1;
        for(auto it : adjLs[start]){
            if(!vis[it]){
                dfs(adjLs,vis,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjLs[n];    
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++) vis[i]=0;
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                res++;
                dfs(adjLs,vis,i);
            }
        } 
        return res;   
    }
};
