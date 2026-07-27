class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int l=0;
        int h=n*m-1;

        while(l<=h){
            int mid=l+(h-l)/2;
            int r=mid/m;     //converting index into 1D
            int c=mid%m;
            if(matrix[r][c]==target){
                return true;
            }
            else if(matrix[r][c]<target) l=mid+1;
            else h=mid-1;
        }
        return false;
    }
};