class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int>prf(n);
        prf[0] = (s[0] == '0');

        for(int i = 1;i<n;i++)prf[i] = prf[i-1] + (s[i]=='0');
        int cnt = 0;
        int ans = 0;
        for(int i = n-1;i>0;i--){
            cnt = cnt + (s[i]=='1');
            ans = max(ans,prf[i-1]+cnt);
        }
        return ans;
    }
};