class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax=0;
        int currMin=0;
        int maxi=nums[0];
        int mini=nums[0];
        int t=0;

        for(int i=0;i<nums.size();i++){
            t=t+nums[i];      //block that
            currMax=max(nums[i], currMax+nums[i]); //normal kadene
            maxi=max(maxi, currMax);

            currMin=min(nums[i], currMin+nums[i]);   //reverse kadene (take minimum sum)
            mini=min(mini, currMin);   
        }  

            if(maxi<0){
                return maxi;
            }
        
        return max(maxi, t-mini);
    }
};