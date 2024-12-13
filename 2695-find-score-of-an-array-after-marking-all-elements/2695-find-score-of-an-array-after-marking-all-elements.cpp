class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<tuple<int,int>>pq;

        for(int i = 0;i<nums.size();i++){
            pq.push({-nums[i],-i});
        }
        vector<bool>vis(nums.size());
        long long ans = 0;
        while(pq.size()){
            auto [val,idx] = pq.top();
            pq.pop();
            //cout<<val<<" "<<idx<<"\n";
            idx = -idx;
            if(!vis[idx]){
                if(idx+1<nums.size())
                    vis[idx+1] = true;
                if(idx>0)
                    vis[idx-1] = true;
                
                vis[idx] = true;
                ans+=val;
            }
        }
        return abs(ans);
    }
};