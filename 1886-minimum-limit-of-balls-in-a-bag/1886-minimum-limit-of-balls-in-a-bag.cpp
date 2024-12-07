class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // auto solve = [&](auto&self,int n,int& threshold)->int{
        //     if(n<=threshold)return 0;
        //     int ret = 1;
        //     int left = self(self,n/2,threshold);
        //     int right =self(self,(1+n)/2,threshold);
        //     left = min(left,((n/2+threshold-1)/threshold)-1);
        //     right = min(right,(((n+1)/2+threshold-1)/threshold)-1);
        //     ret = ret + left + right;
        //     return ret;
        // };
        sort(nums.rbegin(),nums.rend());
        auto check = [&](int mx)->bool{
            int need = 0;
            for(auto&ele:nums){
                if(ele<=mx)return true;
                need+=max(0,((ele+mx-1)/mx)-1);
                //cout<<need<<"\n";
                if(need>maxOperations)return false;
            }
            return true;
        };
        int l = 1, r = nums[0];
        int ans = r;
        while(l<=r){
            int md = l+r>>1;
            if(check(md))ans = md,r = md-1;
            else l = md+1;
        }
        return ans;
    }
};