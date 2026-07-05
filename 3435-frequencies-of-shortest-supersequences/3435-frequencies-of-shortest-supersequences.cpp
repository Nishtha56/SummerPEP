class Solution {
public:
    vector<vector<int>> supersequences(vector<string>& words) {
        int pre = 0;
        int self = 0;
        int g[26] = {0};

        for (string &s : words) {
            int a = s[0] - 'a';
            int b = s[1] - 'a';
            pre |= (1 << a);
            pre |= (1 << b);

            if (a == b)
                self |= (1 << a);
            else
                g[a] |= (1 << b);
        }

        vector<int> ch;
        for (int i = 0; i < 26; i++) {
            if (pre & (1 << i))
                ch.push_back(i);
        }

        int n = ch.size();
        int mn = 1e9;
        vector<int> ansMask;

        for (int mask = 0; mask < (1 << n); mask++) {
            int dup = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    dup |= (1 << ch[i]);
            }

            if ((dup & self) != self)
                continue;

            int rem = pre & (~dup);
            int cur = rem;
            bool ok = true;

            while (cur) {
                int in = 0;
                int t = cur;

                while (t) {
                    int x = __builtin_ctz(t);
                    in |= g[x];
                    t &= (t - 1);
                }

                int zero = cur & (~in);

                if (zero == 0) {
                    ok = false;
                    break;
                }

                cur ^= zero;
            }

            if (ok) {
                int cnt = __builtin_popcount(dup);

                if (cnt < mn) {
                    mn = cnt;
                    ansMask.clear();
                    ansMask.push_back(dup);
                } else if (cnt == mn) {
                    ansMask.push_back(dup);
                }
            }
        }

        vector<vector<int>> ans;

        for (int dup : ansMask) {
            vector<int> f(26, 0);

            for (int i = 0; i < 26; i++) {
                if (dup & (1 << i))
                    f[i] = 2;
                else if (pre & (1 << i))
                    f[i] = 1;
            }

            ans.push_back(f);
        }

        return ans;
    }
};