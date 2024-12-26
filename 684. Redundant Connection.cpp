class Solution {
public:
int find(int x,vector<int> &parents){
    if(parents[x]==x) return x;
    else return parents[x] = find(parents[x],parents);
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size()+1);
        iota(parents.begin()+1,parents.end(),1);
        vector<int> ans;
        for(auto edge : edges){
            int u = find(edge[0],parents);
            int v = find(edge[1],parents);
            if(u==v){
             ans = {edge[0],edge[1]};
            }
            else{
             parents[u]=v;
            }
        }
        return ans;
    }
};
