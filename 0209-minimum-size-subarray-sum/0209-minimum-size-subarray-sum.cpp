class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {
        int ret = 10000000;
        int l = 0 ,r = 0;
        int sum = 0;
        int n = nums.size();
        while(r<n){
            //cout<<"R: "<<r<<"\n";

            sum+=nums[r];
            while(l<=r&&sum-nums[l]>=tar){
                sum-=nums[l];
                l++;
            }
            if(sum>=tar)
            {
                ret = min(ret,r-l+1);
                //sum -=nums[l],l++;
            }
            //cout<<"L: "<<l<<"\n";

            r++;
            r = max(r,l);

        }

        return (ret==10000000)?0:ret;
    }
};