class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = m - 1;

        // Step 1: find row
        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[mid][n - 1] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        int row = l;
        if (row >= m) return false;

        // Step 2: binary search inside row
        l = 0; 
        r = n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return false;
    }
};