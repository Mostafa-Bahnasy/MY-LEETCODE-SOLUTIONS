class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prf(n),suf(n);
        prf[0]  = nums[0];
        suf[n-1] = nums[n-1];

        for(int i = 1;i<n;i++)prf [i] = prf[i-1]+nums[i];
        for(int i = n-2;i>-1;i--)suf[i] = suf[i+1]+nums[i];
        int ret = 0;
        for(int i = 0;i<n-1;i++){
            if(prf[i]>=suf[i+1])ret++;
        }

        return ret;
    }
};