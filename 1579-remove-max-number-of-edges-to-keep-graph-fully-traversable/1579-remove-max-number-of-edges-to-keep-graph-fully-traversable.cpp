class Solution {
public:
    int findPar(vector<int> &par, int node){
        if(par[node] == node) return node;
        return par[node] = findPar(par, par[node]);
    }
    void unionBySize(vector<int> & par, vector<int> &sz, int u, int v){
        int parU = findPar(par, u);
        int parV = findPar(par, v);
        if(sz[parU] >= sz[parV]){
            par[parV] = parU;
            sz[parU] += sz[parV];
        }
        else{
            par[parU] = parV;
            sz[parV] += sz[parU];
        }
    }
    int helper(vector<vector<int>>& edges, vector<int> par, vector<int> sz, int type, int n){
        int cc=0;
        for(int i = 0; i<edges.size(); i++){
            int typ = edges[i][0];
            if(typ == type){
                int u = edges[i][1], v = edges[i][2];
                int parU = findPar(par, u), parV = findPar(par, v);
                if(parU == parV) continue;
                unionBySize(par, sz, u, v);
                cc++;
            }
        }
        return cc ;

    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> par(n+1);
        for(int i = 1; i<=n; i++) par[i] = i;
        vector<int> sz(n+1, 1);
        int cted = 0;
        // first traverse the type 3 edges
        for(int i = 0; i<edges.size(); i++){
            int type = edges[i][0];
            if(type == 3){
                int u = edges[i][1], v = edges[i][2];
                int parU = findPar(par, u), parV = findPar(par, v);
                if(parU == parV) continue;
                unionBySize(par, sz, u, v);
                cted++;
            }
        }
        if(cted == n-1) return edges.size() - (n-1);
        // alice edges
        int canAlice = helper(edges, par, sz, 1,  n);
        int canBob = helper(edges, par, sz, 2,  n);
        if(canAlice + cted == n-1 && canBob + cted == n-1) 
        return edges.size() - cted - canAlice - canBob ;
        return -1;
    }
};