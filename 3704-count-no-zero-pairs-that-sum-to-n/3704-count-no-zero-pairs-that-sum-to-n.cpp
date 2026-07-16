class Solution {
public:
    long long dp[16][2][2][2];
    long long f(int ind, int eza, int ezb, int c, string &s){
        if(ind == s.size()-1 && c == s[ind] - '0' ) return 1;
        if(ind == s.size()) return c == 0 ;
        if(dp[ind][eza][ezb][c] != -1) return dp[ind][eza][ezb][c];
        long long ans = 0;
        for(int i = 0; i<=9; i++){
            if(ind == 0 && i == 0) continue;
            if(eza && i != 0) continue;
            for(int j = 0; j<=9; j++){
                if(ind == 0 && j == 0) continue;
                if(ezb && j != 0) continue;
                int sum = (i+j+c);
                if(sum%10 == s[ind]-'0'){
                    ans += f(ind+1, eza|(i==0), ezb|(j==0), sum/10, s);
                }
            }
        }
        return dp[ind][eza][ezb][c] = ans;
    }
    long long countNoZeroPairs(long long n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, 0, s);
    }
};