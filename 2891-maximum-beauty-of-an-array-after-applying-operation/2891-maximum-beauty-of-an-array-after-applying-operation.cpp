class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int prf[300010] = {};
        //int shft = 1e5;
        for(auto&i:nums){
            prf[i+2*k+1]--;
            prf[i]++;
        }
        int ans = max(1,prf[0]);

        for(int i = 1;i<=3e5+5;i++){
            prf[i] = prf[i] + prf[i-1];
            ans = max(ans,prf[i]);
        }
        return ans;
    }
};