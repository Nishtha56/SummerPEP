class Solution {
public:
    int dp[23][2][2][200];
    int mod = 1e9+7;
    int f(int ind, int tight, int lz, int ds, string s, int min_sum, int max_sum){
        // base case
        if(ind == s.size()) return ds>=min_sum && ds<=max_sum;
        if(dp[ind][tight][lz][ds] != -1) return dp[ind][tight][lz][ds];
        int ul = tight ? s[ind]-'0' : 9;
        int ans = 0;
        for(int i = 0; i<=ul; i++){
            if(lz && (i==0)) ans = ((ans + f(ind+1, 0, 1, ds, s, min_sum, max_sum))%mod+mod)%mod;
            else ans = ((ans + f(ind+1, tight & (i==ul), 0, ds+i, s, min_sum, max_sum))%mod+mod)%mod;
        }
        return dp[ind][tight][lz][ds] = ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        int ansNum2 = f(0, 1, 1, 0, num2, min_sum, max_sum);
        memset(dp, -1, sizeof(dp));
        int ansNum1 = f(0, 1, 1, 0, num1, min_sum, max_sum);
        int sumn1 = 0;
        for(int i = 0; i<num1.size(); i++){
            sumn1 += (num1[i]-'0');
        }
        if(sumn1 <= max_sum && sumn1 >= min_sum)
        return ((ansNum2 - ansNum1 + 1)%mod + mod)%mod;
        return ((ansNum2 - ansNum1) + mod)%mod;
    }
};