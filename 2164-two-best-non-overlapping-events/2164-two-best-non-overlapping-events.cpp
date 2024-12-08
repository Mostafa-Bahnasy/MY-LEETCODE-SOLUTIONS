class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        vector<tuple<int,int,int>>left(n);
        int idx = 0;
        for(auto&v:events){
            left[idx] = {v[0],v[1],v[2]};
            idx++;
        }
        sort(left.begin(),left.end());
        
        int can = 0;
        multiset<pair<int,int>>open;
        int ans = 0;
        for(auto&[l,r,val]:left){
            while(open.size()&&open.begin()->first<l){
                can= max(open.begin()->second,can);
                open.erase(open.begin());
            }
            //int add = 0;
            //if(can.size())add = *prev(can.end());
            ans = max(ans,val+can);
            open.insert({r,val});
        }
        return ans;

        //return ans;
    }
};