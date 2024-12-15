class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        

        unordered_map<string,vector<int>>idx;
        int i = 0;
        for(auto s:strs){
            sort(s.begin(),s.end());
            idx[s].push_back(i);
            i++;
        }

        vector<vector<string>>ret;
        for(auto&[h,id]:idx){
            ret.push_back({});
            for(auto&ii:id){
                ret.back().push_back(strs[ii]);
            }
        }
        return ret;
    }
};