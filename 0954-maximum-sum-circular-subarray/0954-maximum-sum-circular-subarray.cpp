class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        auto solveKad =[&]()->void{
            int sum = nums[0];
            ans = nums[0];
            for(int i = 1;i<n;i++){
                sum = max(sum+nums[i],nums[i]);
                ans = max(ans,sum);
            }
        };
        
        auto prfsuf =[&]()->void{
            auto prf = nums;
            auto suf = nums;
            for(int i = 1;i<n;i++)prf[i] = prf[i] + prf[i-1];
            for(int i = n-2;i>-1;i--)suf[i] = suf[i] + suf[i+1];
            for(int i = 1;i<n;i++)prf[i] = max(prf[i] , prf[i-1]);
            for(int i = n-2;i>-1;i--)suf[i] =max( suf[i] , suf[i+1]);
            
            for(int i = 0;i<n-1;i++){
                ans =  max(ans,prf[i]+suf[i+1]);
            }
        };
        solveKad();
        prfsuf();
        return ans;
    }
};