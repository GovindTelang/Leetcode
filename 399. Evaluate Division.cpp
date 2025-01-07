class Solution {
    unordered_map<string,vector<pair<string,double>>> adjList;
    unordered_map<string,bool> vis;
    double queryAns;
public:
    bool dfs(string startNode,string endNode,double runningProd){
        if(adjList.find(startNode)==adjList.end() || adjList.find(endNode) == adjList.end()){
            return false;
        }
        if(startNode == endNode && adjList.find(startNode)!=adjList.end()){
            queryAns = runningProd;
            return true;
        }
        bool tempAns = false;
        vis[startNode] = true;

        for(int i=0;i<adjList[startNode].size();i++){
            if(!vis[adjList[startNode][i].first]){
                tempAns = dfs(adjList[startNode][i].first,endNode,runningProd*adjList[startNode][i].second);
                if(tempAns){
                    break;                  //why does break work and return true as soon as we find an ans does not as it would have worked for a single query but not for multiple queries Because we have to solve m queries and there is only single visited vector. For next query your visited vector should have all false. This is why you have to mark the node false also before returning. If there was only 1 query then it would have worked.
                }
            }
        }
        vis[startNode]=false;
        return tempAns;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        int m = queries.size();
        vector<double> ans(m);
        for(int i=0;i<n;i++){
            adjList[equations[i][0]].push_back({equations[i][1],values[i]});
            adjList[equations[i][1]].push_back({equations[i][0],1/values[i]});
            vis[equations[i][0]]=false;
            vis[equations[i][1]]=false;
        }
        for(int i=0;i<m;i++){
            queryAns = 1;
            bool pathFound = dfs(queries[i][0],queries[i][1],1);
            if(pathFound) ans[i] = queryAns;
            else ans[i] = -1;
        }
        return ans;
    }
};
