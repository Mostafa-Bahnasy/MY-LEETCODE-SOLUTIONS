class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size();
        //sort(v.begin(),v.end());
        std::map<int,int>mp;
        for(int i =0;i<n;i++){
            mp[v[i]]= i;
        }
        set<vector<int>>ret;
        //for(auto&[num,vec]:mp)for(auto&j:vec)std::cout<<num<<" "<<j<<"\n";
        //set<vector<int>>pairs;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j+1<n;j++){
                int need = -v[i] - v[j];
                if(mp.count(need)&&mp[need]>j){
                    vector<int>tmp = {v[i],v[j],need};
                    sort(tmp.begin(),tmp.end());
                    ret.insert(tmp);
                }
            }
        }

        vector<vector<int>>vv;
        for(auto&i:ret)vv.push_back(i);
        return vv;
    }
};