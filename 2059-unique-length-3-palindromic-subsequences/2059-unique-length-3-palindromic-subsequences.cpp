class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // vector<string>pal;
        // for(char a = 'a';a<='z';a++){
        //     for(char b = 'a';b<='z';b++){
        //         string tmp;
        //         tmp +=a;
        //         tmp+=b;
        //         tmp+=a;
        //         pal.push_back(tmp);
        //     }   
        // }

        vector<int>pos[26];

        for(int  i =0;i<s.size();i++){
            pos[s[i]-'a'].push_back(i);
        }
        int ans = 0;
        for(int i = 0;i<26;++i){
            if(pos[i].size()<2)continue;
            int left = pos[i][0]+1;
            int right = pos[i].back()-1;
            if(left>right)continue;
            for(int j = 0;j<26;++j){
                auto &v = pos[j];
                auto it = lower_bound(v.begin(),v.end(),left);
                if(it!=v.end() and *it<=right){
                    ans++;
                }
            }

        }
        return ans;
    }
};