class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)return false;

        int c[26] ={};
        for(auto&i:s){
            c[i-'a']^=1;
        }
        int cnt  = 0;
        for(int i = 0;i<26;i++){
            cnt+=c[i];
        }

        return cnt<=k;
    }
};