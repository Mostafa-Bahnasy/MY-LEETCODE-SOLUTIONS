class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int>dp(400);

        for(int i = 1;i<=370;i++){
            if(find(days.begin(),days.end(),i)!=days.end()){
                dp[i] = min({dp[i-1]+costs[0] , dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]});
            }else{
                dp[i] = dp[i-1];
            }
        }

        return dp[days.back()];
    }
};