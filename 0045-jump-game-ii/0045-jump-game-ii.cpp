class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n  =nums.size();
        int r = nums[0];
        if(n==1)return 0;
        int ans  = 0;
        for(int i = 1;i<n;i++){
            int mx = 0;
            while(i<n&&i<=r){
                mx= max(mx,i+nums[i]);
                i++;
            }
            i = r;
            r = mx;
            ans++;
        }
        return ans;
    }
};