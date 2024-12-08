class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& left) {
        int n = left.size();
        
        sort(left.begin(),left.end());
        
        int can = 0;
        unordered_map<int,int>mp;
        priority_queue<int, vector<int>, greater<int>> open;
        int ans = 0;
        for(auto&v:left){
            //cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
            while(open.size()&&open.top()<v[0]){
                can= max(mp[open.top()],can);
                open.pop();
            }
            ans = max(ans,v[2]+can);
            open.push(v[1]);
            mp[v[1]] = max(v[2],mp[v[1]]);
        }
        return ans;

        //return ans;
    }
};