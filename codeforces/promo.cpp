#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(auto& a : arr) cin >> a;
    sort(arr.begin(), arr.end());
    vector<int> pref(n+1);
    for(int i = 0; i < n; i++) pref[i+1] = pref[i] + arr[i];
    while(q--){
        int x, y; cin >> x >> y;
        int freestart = n-x;
        int freeend = freestart + y - 1;
        cout << pref[freeend+1] - pref[freestart] << endl;
    }

}
