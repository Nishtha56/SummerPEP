#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        auto it=upper_bound(arr.begin(), arr.end(), a);
        cout<<it-arr.begin();
        cout<<endl;
    }
}