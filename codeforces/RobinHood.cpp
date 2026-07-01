#include <bits/stdc++.h>
using namespace std;

const int MAX = 200005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n + 1);

        map<int, bitset<5000>> mp;   

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        while (q--) {
            int l, r;
            cin >> l >> r;

            map<int, int> freq;

            for (int i = l; i <= r; i++)
                freq[a[i]]++;

            bool ok = true;
            for (auto x : freq) {
                if (x.second % 2) {
                    ok = false;
                    break;
                }
            }

            cout << (ok ? "YES\n" : "NO\n");
        }
    }
}