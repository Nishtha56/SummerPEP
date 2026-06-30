class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        // int pre=0, post=0;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         pre=pre+nums[j];
        //     }
        //     for(int j=i+1;j<n;j++){
        //         post=post+nums[j];
        //     }

        //     if(pre==post){
        //         return i;
        //     }
        //     pre=0;
        //     post=0;
        // }

        int total=0, right=0, left=0;

        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        for(int i=0;i<n;i++){
            right=total-left-nums[i];

            if(left==right){
                return i;
            }
            left=left+nums[i];
        }
        return -1;
    }
};