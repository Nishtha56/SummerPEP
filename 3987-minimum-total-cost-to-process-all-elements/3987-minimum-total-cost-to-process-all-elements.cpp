class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int curr=k;
        long long tot=0;
        for(int i=0;i<nums.size();i++){
            if(curr<nums[i]){
                int n=nums[i]-curr;
                long long op=(n+k-1)/k;

                tot=tot+op;
                curr=curr+op*k;
            }

            curr=curr-nums[i];
        }

        long long mod=1000000007;
        int c=0;
        if(tot%2==0){
            long long prev=(tot/2)%mod;
            long long next=(tot+1)%mod;
            c=(prev*next)%mod;
        }

            
        else{
            long long a=tot%mod;
            long long b=((tot+1)/2)%mod;
            c=(a*b)%mod;
        }

        
        return c;
    }
};