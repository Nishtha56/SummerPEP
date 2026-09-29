// (m+n)/2<=100 enough for use
// dp[i][j] denotes the mask with pth bit set where path sum=p to (i, j)
using u128=__uint128_t;
u128 dp[100]; // reduced space
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        const int m=grid.size(), n=grid[0].size(), lim=(n+m)>>1;
        if (((m+n)&1)==0 || grid[0][0]==')' || grid[m-1][n-1]=='(') 
            return 0;
        const u128 maxMask=(u128(1)<<(lim+1))-1;
        // reset
        fill_n(dp, n, 0);

        dp[0]=(u128)1<<1;
        int p=1;
        for(int j=1; j<n; j++){
            p+=(grid[0][j]=='(')-(grid[0][j]==')');
            if (p<0|| p>lim) break;
            dp[j]=(u128)1<<p;
        }
        p=1;
        for(int i=1; i<m; i++){
            p+=(grid[i][0]=='(')-(grid[i][0]==')');
            if (dp[0]==0 || p<0|| p>lim) dp[0]=0;
            else dp[0]=(u128)1<<p;
            for(int j=1; j<n; j++){
                dp[j]=dp[j-1]|dp[j];
                dp[j]=(grid[i][j]=='(')? (dp[j]<<1)& maxMask
                : dp[j]>>1;
            }
        }
        return dp[n-1]&1==1;
    }
};