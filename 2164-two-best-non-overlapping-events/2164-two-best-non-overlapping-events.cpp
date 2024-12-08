class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& left) {
        int n = left.size();
        
        sort(left.begin(),left.end());
        
        int can = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> open;
        int ans = 0;
        for(auto&v:left){
            //cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
            while(open.size()&&open.top().first<v[0]){
                can= max(open.top().second,can);
                open.pop();
            }
            ans = max(ans,v[2]+can);
            open.push({v[1],v[2]});
        }
        return ans;

        //return ans;
    }
};