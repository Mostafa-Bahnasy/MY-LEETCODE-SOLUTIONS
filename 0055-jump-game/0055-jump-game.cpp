class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();

        queue<int>q;
        vector<bool>vis(n+1);
        q.push(0);
        vis[0] = true;

        while(q.size()){
            auto tp = q.front();
            q.pop();
            int lim = nums[tp];
            for(int i = 1;i<=lim&&tp+i<n;i++){
                if(!vis[tp+i]){
                    vis[tp+i] = true;
                    q.push(tp+i);
                }
            }
        }
        return vis[n-1];
    }
};