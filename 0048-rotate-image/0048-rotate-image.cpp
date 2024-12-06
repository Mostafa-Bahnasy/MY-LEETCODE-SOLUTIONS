class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int starter = 0;

        while(starter<n/2){
            for(int i =starter;i<n-1-starter;i++){

                int tmp = matrix[n-1-i][starter];
                matrix[n-1-i][starter] = matrix[n-1-starter][n-1-i];
                matrix[n-1-starter][n-1-i] = matrix[i][n-1-starter];
                matrix[i][n-1-starter] = matrix[starter][i];
                matrix[starter][i] = tmp;
            }
            starter++;
        }
        
    }
};