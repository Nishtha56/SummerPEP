class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        long long sum=0;
        int n=monsters.size();
        vector<long long> arr(n+1, 0);

        for(auto& b : boosts){
            int i=b[0];
            int j=b[1];
            int k=b[2];

            arr[i]=arr[i]+k;
            if(j+1<n){
                arr[j+1]-=k;
            }
            
        }

        vector<long long> us(n, 0);
        for(int i=0;i<n;i++){
            sum+=arr[i];
            us[i]=sum;
        }

        long long ans=0;

        for(int i=n-1;i>=0;i--){
            long long a=monsters[i];
            long long b=us[i];

            if(ans==0){
                ans=max(0LL, a-b);
            }
            else{
                ans=ans+a;
            }
                
        }

        return ans;
    }
};