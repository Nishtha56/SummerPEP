class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2]+1;
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});
        vector<int> dis(n, INT_MAX);
        dis[0] = 0;
        while(pq.size()){
            int node = pq.top().first, newDis = pq.top().second;
            pq.pop();
            if(dis[node] < newDis) continue;
            for(int i = 0; i<adj[node].size(); i++){
                int adjNode = adj[node][i].first, wt = adj[node][i].second;
                if(dis[adjNode] > newDis + wt){
                    dis[adjNode] = newDis+wt;
                    pq.push({adjNode, newDis+wt});
                }
                
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(dis[i] <= maxMoves) ans++;
        }
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            int ansFromU = max(0, maxMoves - dis[u]);
            int ansFromV = max(0, maxMoves - dis[v]);
            int temp = ansFromU + ansFromV > 0 ? ansFromU + ansFromV : 0;
            ans += min(wt, temp);
        }
        return ans;
    }
};