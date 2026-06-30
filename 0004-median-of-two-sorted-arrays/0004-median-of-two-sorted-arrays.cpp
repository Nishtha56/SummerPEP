class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double mid=0.0;
        int n=nums1.size();
        int m=nums2.size();
        vector<int> nums(n+m);

        int i=0, j=0, k=0;

        while(i<n && j<m){
            nums[k++] = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];

        }
        while(i<n){
            nums[k++]=nums1[i++];
        }
        while(j<m){
            nums[k++]=nums2[j++];
        }
        if(k%2!=0){
            mid=nums[k/2];
        }
        else{
            mid=(nums[k/2] + nums[(k/2)-1])/2.0;
        }
        return mid;
    }
};