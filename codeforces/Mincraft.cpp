#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;



int main(){
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(int i = 0; i<n; i++) cin>>v[i];
    //prefix
    vector<long long> pref(n, 0);
    for(int i = 1; i<n; i++){
        if(v[i]- v[i-1] < 0) pref[i] = pref[i-1] + v[i-1]-v[i];
        else pref[i] = pref[i-1];
    }
    vector<long long> suff(n, 0);
    for(int i = n-2; i>=0; i--){
        if(v[i]- v[i+1] < 0) suff[i] = suff[i+1] + v[i+1]-v[i];
        else suff[i] = suff[i+1];
    }
    for(int i = 0; i<q; i++){
        int l,r; cin>>l>>r;
        if(l<r){
            cout<<pref[r-1]-pref[l-1]<<"\n";
        }else{
            cout<<-suff[l-1]+suff[r-1]<<"\n";
        }
    }
    return 0;
}