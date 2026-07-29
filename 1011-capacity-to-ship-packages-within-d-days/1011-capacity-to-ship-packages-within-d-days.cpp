class Solution {
public:
    int func(vector<int> &nums, int mid){
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
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(), weights.end());
        long long h=0;

        for(int i:weights){
            h=h+i;
        }

        while(l<h){
            int mid=l+(h-l)/2;
            int s=func(weights, mid);

            if(s<=days){
                h=mid;
            }
            else{
                l=mid+1;
            }

        }
        return l;
    }
};