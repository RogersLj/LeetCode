class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;

        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = m * n -1;

        while(l < r){
            int mid = l + r + 1 >> 1;
            if(matrix[mid / m][mid % m] <= target) l = mid;
            else r = mid - 1;
        }

        return matrix[r / m][r % m] == target;

    }
};
