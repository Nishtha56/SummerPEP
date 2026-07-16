class Solution {
public:
    long long gcd(int a, int b){
        if(b==0){
            return a;
        }
        return gcd(b, a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int a=0;

        for(int i=0;i<n;i++){
            a=max(a, nums[i]);
            ans.push_back(gcd(a, nums[i]));
        }

        sort(ans.begin(), ans.end());

        int l=0, r=ans.size()-1;
        long long sum=0;

        while(l<r){
            sum+=gcd(ans[l], ans[r]);
            l++;
            r--;
        }
        return sum;
        
    }
};