class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        int peak=-1;

        if(n<3) return false;
        for(int i=1;i<n-1;i++){
            if(arr[i-1]< arr[i] && arr[i]>arr[i+1]){
                peak=i;
                break;
            }
            else if(arr[i-1]==arr[i]){
                return false;
            }
        }
        if(peak==-1){
            return false;
        }

        for(int i=1;i<=peak;i++){
            if(arr[i-1]>=arr[i]){
                return false;
            }
        }

        for(int i=peak+1;i<n;i++){
            if(arr[i-1]<=arr[i]){
                return false;
            }
        }
        return true;
    }
};