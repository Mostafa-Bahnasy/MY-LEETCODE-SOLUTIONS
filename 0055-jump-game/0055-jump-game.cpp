class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int r = nums[0];
        for(int i = 1;i<n;i++){
            if(r>=i)r = max(r,i+nums[i]);
        }
        return r>=n-1;
    }
};