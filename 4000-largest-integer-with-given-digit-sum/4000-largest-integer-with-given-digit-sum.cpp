class Solution {
public:
    int largestInteger(int n, int s) {
        if(s>9*n){
            return -1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int mini=min(9,s);
            ans=ans*10+mini;
            s=s-mini;
        }

        

        return ans;
    }
};