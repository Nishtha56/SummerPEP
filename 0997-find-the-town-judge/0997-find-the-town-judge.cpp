class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n+1);

        for(auto&it:trust){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
        }
        vector<int> in(n+1, 0);
        vector<int> out(n+1, 0);

        for(auto&it:trust){
            int u=it[0];
            int v=it[1];

            in[v]++;
            out[u]++;
        }


        for(int i=1;i<=n;i++){
            if(in[i]==n-1 && out[i]==0){
                return i;
            }
        }
        
        return -1;

    }
};