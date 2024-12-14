class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        int l = 0, r = 0;
        int n = nums.size();
        multiset<int>ms;
        long long ans = 0;
        while(r<n){
            ms.insert(nums[r]);
            while(*prev(ms.end())-*ms.begin() > 2){
                ms.erase(ms.find(nums[l]));
                l++;
            }

            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};