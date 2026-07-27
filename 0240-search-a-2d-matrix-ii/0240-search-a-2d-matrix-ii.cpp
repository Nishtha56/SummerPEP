class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int l=0;
        int r=m-1;

        //tc: O(n+m)

        while(l<n && r>=0){
            if(matrix[l][r]==target){
                return true;
            }
            else if(matrix[l][r]>target){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
};