class Solution {
public:
    bool bfs(int src, vector<int> & vis, vector<vector<int>>& graph){
        vis[src]=0;
        queue<int> q;
        q.push(src); 

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(auto& node : graph[curr]){
                if(vis[node]==-1){
                    vis[node]=!vis[curr];
                    q.push(node);
                }
                else if(vis[node]==vis[curr]){
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(int node, int col, vector<int> &vis, vector<vector<int>> &adj){
        vis[node]=col;
        for(auto& curr : adj[node]){
            if(vis[curr]==-1){
                if(!dfs(curr, !col, vis, adj)){
                    return false;
                }
                   
            }
            else if(vis[curr]==col){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> vis(V, -1);
        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                if(!bfs(i, vis, graph)){
                //if(dfs(i, 0,vis, graph)==0){
                    return false;
                }
            }
        }
        return true;
    }
};