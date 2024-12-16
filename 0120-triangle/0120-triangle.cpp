class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<int>dp(1);
        dp[0] = triangle[0][0];

        for(int i = 1;i<n;i++){
            vector<int>cur(i+1,INT_MAX);
            //for(auto&k:dp)cout<<k<<" ";cout<<"\n";
            for(int j =0;j<=i;j++){
                if(j-1>=0){
                    cur[j] = min(dp[j-1]+triangle[i][j],cur[j]);
                }
                if(j<dp.size()){
                    cur[j] = min(dp[j]+triangle[i][j],cur[j]);
                }
            }
            dp =cur;
        }
        //for(auto&k:dp)cout<<k<<" ";cout<<"\n";

        return *min_element(dp.begin(),dp.end());
    }
};