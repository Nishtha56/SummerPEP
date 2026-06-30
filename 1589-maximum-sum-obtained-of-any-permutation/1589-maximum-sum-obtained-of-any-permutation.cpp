class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {

        int n = nums.size();
        const int MOD = 1e9 + 7;

        vector<long long> diff(n + 1, 0);

        // Line Sweep (Difference Array)
        for (auto &r : requests) {
            int l = r[0];
            int rr = r[1];

            diff[l]++;

            if (rr + 1 < n)
                diff[rr + 1]--;
        }

        // Prefix Sum -> Frequency of each index
        vector<long long> freq(n);
        freq[0] = diff[0];

        for (int i = 1; i < n; i++)
            freq[i] = freq[i - 1] + diff[i];

        // Pair largest frequency with largest number
        sort(freq.begin(), freq.end());
        sort(nums.begin(), nums.end());

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans = (ans + (freq[i] * nums[i]) % MOD) % MOD;
        }

        return ans;
    }
};