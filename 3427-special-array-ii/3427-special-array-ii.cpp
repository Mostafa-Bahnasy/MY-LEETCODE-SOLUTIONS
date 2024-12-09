class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool>ret;
        vector<pair<int,int>>right;// r, l;
        for(int i  = 0; i<n; i++){
            int j = i;
            int match = (nums[i]&1);
            while(j<n&&(nums[j]&1)==match){
                j++;
                match^=1;
            }
            right.push_back({j-1,i});
            i = j-1;
        }
        
        auto get =[&](int val)->int{
            int l  = 0 ,r = right.size()-1;
            int ret = -1;
            while(l<=r){
                int md = (l+r)>>1;
                if(right[md].first>=val)ret= md,r = md-1;
                else l = md+1;
            }
            return ret;
        };
        for(auto&v:queries){
            auto[l,r] = tie(v[0],v[1]);
            //cout<<l<<" "<<r<<"\n";
            auto it = get(l);
           // cout<<it<<"\n";
            if(it==-1)ret.push_back(false);
            else{
                ret.push_back((right[it].second<=l&&r<=right[it].first));
            }
        }
        return ret;
    }
};