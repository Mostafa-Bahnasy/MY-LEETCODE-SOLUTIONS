class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int>mn(n);
        mn[0] = nums[0];
        for(int i = 1;i<n;i++)mn[i] = min(mn[i-1],nums[i]);

        set<int>st;
        st.insert(nums.back());
        for(int i = n-2;i>0;i--){
            int left = mn[i-1];
            int cur = nums[i];
            auto nxt = st.upper_bound(left);
            if(!(nxt==st.end())&&*nxt<cur)return true;
            st.insert(cur);
        }
        return false;
    }
};