class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>v(n);
        for(auto&vv:edges){
            auto [a,b] = tie(vv[0],vv[1]);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<int>sub(n);
        auto add = [&](int a,int b)->int{
            a+=k;
            b+=k;
            a%=k;
            b%=k;
            return (a+b)%k;
        };
        int ans= 0;
        auto dfs = [&](auto&self,int node =0 ,int root =-1)->void{
            sub[node] = values[node]%k;
            //cout<<node<<"\n";
            for(auto&to:v[node]){
                if(to==root)continue;
                self(self,to,node);
                sub[node] = add(sub[node],sub[to]);

            }
            if(sub[node]==0){
                ans++;
            }
        };
        dfs(dfs);
        return ans;
    }
};