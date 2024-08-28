class Solution {
public:
    typedef pair<double,int> P; //(prob,node)
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>> adj;
        vector<double> result(n,0);
        for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        double prob = succProb[i];

        adj[u].push_back({v,prob});
        adj[v].push_back({u,prob});
        }
        priority_queue<P> pq;
        result[start_node]=1;
        pq.push({1.0,start_node});

        while(!pq.empty()){
        double curr_prob = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();
        for(auto &temp : adj[curr_node]){
            double adjProb = temp.second;
            int adjNode = temp.first;

            if(result[adjNode] < curr_prob*adjProb){
                result[adjNode] = curr_prob*adjProb;
                pq.push({result[adjNode],adjNode});
            }
          }
        }
        return result[end_node];
    }
};