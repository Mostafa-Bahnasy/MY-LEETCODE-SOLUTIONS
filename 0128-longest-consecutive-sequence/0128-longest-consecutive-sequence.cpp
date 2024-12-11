class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto&i:nums)s.insert(i);
        int ans  = 0;
        for(auto&i:nums){
            int cur = i;
            //s.erase(cur);
            while(s.count(cur-1))cur--;
            
            //ans = max(ans,i - cur+1);
            int cnt = 0;
            for(int j = cur;s.count(j);j++){
                cnt++;
                s.erase(j);
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};