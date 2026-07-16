class Solution {
public:
    void f(vector<vector<pair<long long, long long>>> &adj, int node, int k,  vector<vector<long long>> &dp, long long par){
        vector<long long> res;
        long long temp = 0;
        // adj iterate
        for(int i = 0; i<adj[node].size(); i++){
            long long v = adj[node][i].first, w =adj[node][i].second;
            if(v == par) continue;
            // nt
            f(adj, v, k, dp, node);
            temp += dp[v][0];
            res.push_back(dp[v][1] - dp[v][0] + 1ll*w);
            // res.push_back(dp[v][0] - dp[v][1] + 1ll*w);

        }
        dp[node][0]= dp[node][1] = temp;
        sort(res.rbegin(), res.rend());
        for(int i = 0; i<res.size() && i<k; i++){
            if(res[i]>0)dp[node][0] += res[i];
        }
        for(int i = 0; i<res.size() && i<k-1; i++){
            if(res[i]>0)dp[node][1] += res[i];
        }

    }
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        // adj list
        int n = edges.size()+1;
        vector<vector<pair<long long, long long>>> adj(n);
        for(int i = 0; i<n-1; i++){
            long long u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v,1ll*w});
            adj[v].push_back({u,w});
        }
        vector<vector<long long>> dp(n, vector<long long>(2,-1));
        f(adj, 0, k, dp, -1);
        return dp[0][0];
    }
};