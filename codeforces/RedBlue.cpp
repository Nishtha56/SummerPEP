#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        vector<int> red(a);
        for(int i=0;i<a;i++){
            cin>>red[i];
        }

        int b;
        cin>>b;
        vector<int> blu(b);
        for(int i=0;i<b;i++){
            cin>>blu[i];
        }

        vector<int> prea(a);
        vector<int> preb(b);

        prea[0]=red[0];
        preb[0]=blu[0];
        for(int i=1;i<a;i++){
            prea[i]=prea[i-1]+red[i];
        }

        for(int i=1;i<b;i++){
            preb[i]=preb[i-1]+blu[i];
        }

        int r=max(0,*max_element(prea.begin(), prea.end()));
        int c=max(0,*max_element(preb.begin(), preb.end()));

        cout<<(r+c);
        cout<<endl;
        
    }
}