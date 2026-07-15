#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int m = digits.size();
        int len = s.size();
        int ans = 0;

        for (int i = 1; i < len; i++)
            ans += pow(m, i);

        for (int i = 0; i < len; i++) {
            bool ok = false;

            for (auto d : digits) {
                if (d[0] < s[i])
                    ans += pow(m, len - i - 1);
                else if (d[0] == s[i]) {
                    ok = true;
                    break;
                } else
                    break;
            }

            if (!ok)
                return ans;
        }

        return ans + 1;
    }
};