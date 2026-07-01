#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>
using namespace std;


int main(){
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        string s; cin>>s;
        set<int> st;
        for(int i = 0; i<m; i++){
            int temp ; cin>>temp;
            st.insert(temp);
        }
        vector<int> v(n,1);
        // process queries
        for(int i = 0; i<n; i++){
            int pos = 1;
            if(i==0){
                if(s[0] == 'A'){
                        pos++;
                }
                else{
                    pos++;
                    // skip all black cells
                    while(st.count(pos))pos++;
                }
                st.insert(pos);
            }
            else if(i == 1){
                if(s[0] == 'A'){
                        pos++;
                }
                else{
                    pos++;
                    // skip all black cells
                    while(st.count(pos))pos++;
                }
                v[1] = pos;
                if(s[1] == 'A'){
                        pos++;
                }
                else{

                    pos++;
                    // skip all black cells
                    while(st.count(pos))pos++;
                }
                st.insert(pos);
            }
            else if(i>1){
                pos = v[i-1];
                // perform i-1st query and ith query
                for(int j = 0; j<2; j++){
                    if(s[i-1+j] == 'A'){
                        pos++;
                    }
                    else{
                        pos++;
                        // skip all black cells
                        while(st.count(pos))pos++;
                    }
                    if(j == 0) v[i] = pos;
                    if(j == 1) st.insert(pos);
                }
            }
        }
        cout<<st.size()<<endl;
        for(auto it = st.begin(); it!=st.end(); it++){
            cout<<*it<<" ";
        }
        cout<<"\n";
        
    }
    return 0;
}