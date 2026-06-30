class Solution {
public:
    void reverse(int a, int b, vector<int> &nums){
        while(a<b){
            swap(nums[a], nums[b]);
            a++;
            b--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(0, n-1, nums);
        reverse(0, k-1, nums);
        reverse(k, n-1, nums);

    }
};