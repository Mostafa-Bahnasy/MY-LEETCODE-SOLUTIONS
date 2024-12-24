class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();
        vector<vector<int>>v(n+1),vv(1+m);
        
        for(auto&e:edges1){
            auto [a,b] = tie(e[0],e[1]);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        for(auto&e:edges2){
            auto [a,b] = tie(e[0],e[1]);
            vv[a].push_back(b);
            vv[b].push_back(a);
        }
        auto get_dia = [&](auto&self,vector<vector<int>>&v,int node,int root = -1,int lvl = 0)->int{
            int ret = -1;
            for(auto&to:v[node]){
                if(to==root)continue;
                ret = max(ret,self(self,v,to,node,lvl+1));
            }
            if(ret==-1)ret = lvl;
            return ret;
        };

        auto get_far = [&](auto &self,vector<vector<int>>&v,int node,int& ret, int& mx_dia,int root =-1,int lvl = 0)->void{
            if(lvl >mx_dia){
                ret = node;
                mx_dia = lvl;
                // cout<<"Here\n";
                // cout<<ret<<"\n";
            }
            for(auto&to:v[node]){
                if(root==to)continue;
                self(self,v,to,ret,mx_dia,node,lvl+1);
            }
        };

        auto solve =[&](vector<vector<int>>&v)->int{

            int mx_dia = -1;
            int far_node = -1;
            get_far(get_far,v,0,far_node,mx_dia);
            mx_dia = -1;
            // get_far(get_far,v,far_node,far_node,mx_dia);
            // cout<<"N: "<<far_node<<"\n";
            int d1 = get_dia(get_dia,v,far_node);
            // cout<<"d: "<<d1<<"\n";
            return d1;    
        };

        int d1 = solve(v);
        int d2 = solve(vv);

        return max({d1,d2,(d1+1)/2 + (d2+1)/2 + 1});
    }
};