#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    long long total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    if (total % 3 != 0) {
        cout << 0;
        return 0;
    }

    long long part = total / 3;

    vector<long long> suf(n, 0);
    long long sum = 0;

    for (int i = n - 1; i >= 0; i--) {
        sum += a[i];
        if (sum == part)
            suf[i] = 1;
    }

    for (int i = n - 2; i >= 0; i--)
        suf[i] += suf[i + 1];

    long long ans = 0;
    sum = 0;

    for (int i = 0; i <= n - 3; i++) {
        sum += a[i];
        if (sum == part)
            ans += suf[i + 2];
    }

    cout << ans;
}