class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ret;

        int cnt[26] = {};

        for(auto&s:words2){
            int cur[26] = {};
            for(auto ch:s){
                cur[ch-'a']++;
            }
            for(int i = 0;i<26;i++){
                cnt[i] = max(cnt[i],cur[i]);
            }
        }

        auto get =[&](string &s)->vector<int>{
            vector<int>ret(26);
            for(auto&i:s){
                ret[i-'a']++;
            }
            return ret;
        };

        for(auto&s:words1){
            auto cur = get(s);

            bool is = true;
            for(int i = 0;i<26;i++){
                if(cur[i]<cnt[i]){is = false;break;}
            }
            if(is)ret.push_back(move(s));
        }
        return ret;
    }
};