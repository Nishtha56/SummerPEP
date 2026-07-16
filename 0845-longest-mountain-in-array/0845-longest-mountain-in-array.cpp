class Solution {
public:
    int fun(vector<int>&arr, int mid, int r, int a, bool f){
        if(f){
            for(int i=mid;i>0;i--){
            if(arr[i]>arr[i-1]){
                a++;
            }
            else{
                break;
            }
        }
        }
        else{
            for(int i=mid;i<r-1;i++){
            if(arr[i]>arr[i+1]){
                a++;
            }
            else{
                break;
            }
        }
        }
        return a;
        
    }
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int maxi=0;

        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                int mid=i;

                int a=0, b=0;
                int c=fun(arr, mid, 0, a, true);
                int d=fun(arr, mid, n, b,false);

                maxi=max(maxi, c+d+1);



            }
        }
        return maxi;
    }
};