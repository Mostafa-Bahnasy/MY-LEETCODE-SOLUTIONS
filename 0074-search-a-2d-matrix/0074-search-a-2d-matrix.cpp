class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = n-1;
        int row = -1;
        while(l<=r){
            int md = l+r>>1;
            if(matrix[md][0]<=target){
                row = md;
                l = md+1;
            }else{
                r = md-1;
            }
        }

        if(row==-1)return false;

        l = 0, r = m-1;
        while(l<=r){
            int md = l+r>>1;

            if(matrix[row][md]==target){
                return true;
            }else if(matrix[row][md]>target){
                r = md-1;
            }else l = md+1;
        }

        return false;
    }
};