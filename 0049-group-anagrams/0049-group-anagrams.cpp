class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const long long mod=1e9+7;
        long long base = 37;
        long long pw[110] ={};
        pw[0]=1;
        for(int i= 1;i<105;i++)
            pw[i] = (pw[i-1]*base)%mod;

        auto hash_it =[&](string&s)->long long{
            long long ret = 0;
            int i = 0;
            for(auto& ch:s){
                ret = ret + (((ch-'a')+1)*pw[i])%mod;
                ret%=mod;
                i++;
            }
            return ret;
        };

        unordered_map<long long,vector<int>>idx;
        int i = 0;
        for(auto s:strs){
            sort(s.begin(),s.end());
            long long hsh = hash_it(s);
            idx[hsh].push_back(i);
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