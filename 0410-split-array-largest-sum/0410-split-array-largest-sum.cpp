class Solution {
public:
    int split(vector<int> &nums, int mid){
        int c=1;
        long long sum=0;

        for(int i :nums){
            if(sum+i<=mid){
                sum=sum+i;
            }
            else{
                c++;
                sum=i;
            }
        }
        return c;

    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(), nums.end());
        long long h=0;

        for(int x:nums){
            h=h+x;
        }

        while(l<h){
            int mid=l+(h-l)/2;

            int s=split(nums, mid);

            
            if(s<=k){
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};