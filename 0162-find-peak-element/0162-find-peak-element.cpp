class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=1, n=nums.size()-1, r=n-1;
        int mid=(l+r)/2;
        while(l<=mid){
            if(nums[l]>nums[l-1] && nums[l]>nums[l+1]){
                return l;
            }
            else if(nums[r]>nums[r-1] && nums[r]>nums[r+1]){
                return r;
            }
            else{
                l++;r--;
            }
        }
        if(nums[0]>nums[n]){
            return 0;
        }
        return n;
    }
};