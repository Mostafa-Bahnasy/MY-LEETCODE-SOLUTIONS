class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>suf(n+1);
        for(int i = n-1;i>-1;i--)suf[i] = suf[i+1] + abs(nums[i]);

        auto solve = [&](auto&self,int idx,int need)->int{
            if(idx==n){
                return(need==0);
            }
            int rem = suf[idx];
            if(rem<abs(need))return 0;

            int ret = 0;
            ret += self(self,idx+1,need+nums[idx]);
            ret +=self(self,idx+1,need-nums[idx]);
            return ret;
        };

        return solve(solve,0,target);

    }
};