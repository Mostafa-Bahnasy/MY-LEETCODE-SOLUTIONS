class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+4,0);
        dp[0] = 1;
        const int mod = 1000000007;
        for(int i =1;i<=high;i++){
            if(i-zero>=0)
                dp[i] = (dp[i]+dp[i-zero])%mod;
            if(i-one>=0)
                dp[i] = (dp[i]+dp[i-one])%mod;
            
        }
        int ans = 0;
        for(low;low<=high;low++)ans = (ans+dp[low])%mod;
        return ans;
    }
};