class Solution {
public:
    int minimumLength(string s) {
        int cnt[26] = {};

        for(auto&i:s){
            cnt[i-'a']++;
        }
        int ret = 0;
        for(int i = 0;i<26;i++){
            if(cnt[i]>2){
                if(cnt[i]&1){
                    ret++;
                }else ret+=2;
            }else ret+=cnt[i];
        }

        return ret;
    }
};