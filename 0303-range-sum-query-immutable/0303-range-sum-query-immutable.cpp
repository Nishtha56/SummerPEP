class NumArray {
public:

    vector<int> pre;
    NumArray(vector<int>& nums) {
        pre.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            int a=pre[i-1]+nums[i];
            pre.push_back(a);
        }
        
    }
    
    int sumRange(int left, int right) {
        if(left==0) return pre[right];
        return pre[right]-pre[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */