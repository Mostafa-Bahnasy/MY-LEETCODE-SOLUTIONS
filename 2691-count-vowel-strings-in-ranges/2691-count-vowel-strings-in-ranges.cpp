class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>ret;
        int n = words.size();
        vector<int>prf(n);
        string vowel = "aeiou";
        auto check = [&](string &s)->int{
            if(vowel.find(s.front())!=string::npos and vowel.find(s.back())!=string::npos ){
                return 1;
            }
            return 0;
        };
        for(int i = 0;i<n;i++){
            if(!i)
                prf[i] = check(words[i]);
            else 
                prf[i] = prf[i-1] + check(words[i]);
        }

        for(auto&v:queries){
            int l = v[0];
            int r = v[1];

            int ans = prf[r];
            if(l){
                ans = ans - prf[l-1];
            }

            ret.push_back(ans);
        }

        return ret;
    }
};