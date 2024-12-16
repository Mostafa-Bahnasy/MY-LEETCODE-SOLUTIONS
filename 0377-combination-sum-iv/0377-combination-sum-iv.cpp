class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int>dp(target+4);
        dp[0] = 1;
        //sort()
        for(int i = 1;i<=target;i++){

            for(auto&cur:nums){
                if(i-cur>=0)
                    dp[i]+=dp[i-cur];
            }
        }
        return dp[target];
    }
};