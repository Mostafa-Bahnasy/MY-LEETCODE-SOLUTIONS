class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<pair<int,int>>sor(n);
        for(int i = 0;i<n;i++){
            sor[i] = {heights[i],i};
        }
        sort(sor.begin(),sor.end());

        vector<tuple<int,int,int>>qu;
        int idx = 0;
        for(auto&v:queries){
            auto[x,y] = tie(v[0],v[1]);
            if(x>y)swap(x,y);
            if(x==y||heights[x]<heights[y]){
                qu.push_back({max(heights[x],heights[y]),max(x,y),idx++});

            }
            else{
                qu.push_back({max(heights[x],heights[y])+1,max(x,y),idx++});

            }

        }
        sort(qu.begin(),qu.end());
        set<int>st;

        vector<int>ans(qu.size());
        for(int i = qu.size()-1;i>-1;i--){
            auto [mx_v,mx_i,id] = qu[i];
            while(sor.size()&&sor.back().first >=mx_v){
                st.insert(sor.back().second);
                sor.pop_back();
            }
            auto it = st.lower_bound(mx_i);
            if(it==st.end())
                ans[id] = -1;
            else
                ans[id] = *it;
        }
        return ans;
    }
};