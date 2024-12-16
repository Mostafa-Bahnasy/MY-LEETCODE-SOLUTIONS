class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = 0;
        while(r<n){
            int cur = r;
            while(r<n && nums[r]==nums[cur]){
                r++;
            }
            nums[l] =nums[cur];
            l++;
        }
        return l;
    }
};