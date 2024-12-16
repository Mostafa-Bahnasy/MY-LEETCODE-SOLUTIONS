class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>>pq;
        for(int i = 0;i<nums.size();i++){
            pq.push({-nums[i],-i});
        }

        while(k--){
            auto [v,idx] = pq.top();
            //cout<<v<<" "<<idx<<"\n";
            pq.pop();
            v= -v,idx=-idx;
            nums[idx] = v*multiplier;
            pq.push({-nums[idx],-idx});
        }
        return nums;
    }
};