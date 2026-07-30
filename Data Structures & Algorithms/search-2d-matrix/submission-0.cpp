class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0; int r = m-1;
        int trgtRow = 0;
        while(l <= r){
            trgtRow = (r-l)/2 + l;
            if(matrix[trgtRow][0] > target){
                r = trgtRow - 1;
            }
            else if(matrix[trgtRow][0] < target){
                l = trgtRow + 1;
            }
            else{
                return true;
            }
        }
        r < 0 ? trgtRow = 0 : trgtRow = r;
        l = 0 ; r = n-1;
        while(l <= r){
            int mid = (r-l)/2 + l;
            if(matrix[trgtRow][mid] > target){
                r = mid-1;
            }
            else if(matrix[trgtRow][mid] < target){
                l = mid + 1;
            }
            else return true;
        }
        return false;
    }
};