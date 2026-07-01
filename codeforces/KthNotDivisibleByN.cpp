#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
  

    for(int i=0;i<t;i++){
        int n, k;
        cin>>n>>k;
        cout<<k+((k-1)/(n-1));
        cout<<endl;
    }
}