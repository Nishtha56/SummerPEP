class Solution {
public:
    int findPar(vector<int> &par, int node){
        if(par[node] == node) return node;
        return par[node] = findPar(par, par[node]);
    }
    void unionBySize(vector<int> & par, vector<int> & sz, int u, int v){
        int parU = findPar(par, u);
        int parV = findPar(par, v);
        if(parU == parV) return ;
        if(sz[parU] > sz[parV]){
            // attach to U
            par[parV] = parU;
            sz[parU] += sz[parV];
        }
        else{
            par[parU] = parV;
            sz[parV] += sz[parU];
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<int> par(4*n*n);
        for(int i = 0; i<4*n*n; i++) par[i] = i;
        vector<int> sz(4*n*n, 1);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int first = 4*n*i + 4*j, second = first+1, third = first+2, fourth = first+3;
                if(grid[i][j] == '/'){
                    // union first, last node of this cell and 2nd, 3rd
                    unionBySize(par, sz, first, fourth);
                    unionBySize(par, sz, second, third);
                }
                else if( grid[i][j] == '\\'){
                    // union first,second and third,fourth
                    unionBySize(par, sz, first, second);
                    unionBySize(par, sz, third, fourth);
                }
                else{
                    // union all 4
                    unionBySize(par, sz, first, second);
                    unionBySize(par, sz, third, fourth);
                    unionBySize(par, sz, first, third);
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 && j == 0) continue;
                // join with left
                int first = 4*n*i + 4*j, second = first+1, third = first+2, fourth = first+3;
                if(j>0){
                    unionBySize(par, sz, fourth, fourth-6);
                }
                // join with top
                if(i>0){
                    unionBySize(par, sz, first, 4*n*(i-1) + 4*j + 2);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<4*n*n; i++){
            if(par[i] == i) ans++;
        }
        return ans;
    }
};