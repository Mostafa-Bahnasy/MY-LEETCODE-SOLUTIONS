class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int r = -1;
        int l = 0;
        vector<vector<int>>ret;
        for(auto&v:intervals){
            if(r==-1){
                r = v[1];
                l = v[0];
            }else{
                if(r>=v[0])
                    r = max(r,v[1]);
                else{
                    ret.push_back({l,r});
                    l = v[0];
                    r = v[1];
                }
            }
        }
        ret.push_back({l,r});
        return ret;
    }
};