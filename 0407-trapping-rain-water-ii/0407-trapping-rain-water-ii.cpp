class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m <= 2 || n <= 2)
            return 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Push all boundary cells
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            vis[i][0] = 1;
            vis[i][n - 1] = 1;
        }

        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});
            vis[0][j] = 1;
            vis[m - 1][j] = 1;
        }

        int ans = 0;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int h = cur[0];
            int r = cur[1];
            int c = cur[2];

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = 1;

                    ans += max(0, h - heightMap[nr][nc]);

                    pq.push({max(h, heightMap[nr][nc]), nr, nc});
                }
            }
        }

        return ans;
    }
};