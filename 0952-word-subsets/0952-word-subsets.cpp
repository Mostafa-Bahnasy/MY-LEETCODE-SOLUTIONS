struct TinyInt {
    unsigned int value : 4 = 0; // 4 bits, can store values 0-15
};


class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ret;

        TinyInt cnt[26];

        for(auto&s:words2){
            TinyInt cur[26];
            for(auto ch:s){
                cur[ch-'a'].value++;
            }
            for(int i = 0;i<26;i++){
                cnt[i].value = max(cnt[i].value,cur[i].value);
            }
        }

        auto get =[&](string &s)->array<TinyInt, 26> {
            std::array<TinyInt, 26> ret = {};
            for(auto&i:s){
                ret[i-'a'].value++;
            }
            return ret;
        };

        for(auto&s:words1){
            auto cur = get(s);

            bool is = true;
            for(int i = 0;i<26;++i){
                if(cur[i].value<cnt[i].value){is = false;break;}
            }
            if(is)ret.push_back(move(s));
        }
        return ret;
    }
};