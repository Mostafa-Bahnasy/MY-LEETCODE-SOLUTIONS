class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = target.size();
        int m = words[0].size();
        vector<vector<long long >>col(m,vector<long long>(26));
        for(auto&s:words){
            for(int i  =0;i<m;i++){
                col[i][s[i]-'a']++;
            }
        }
        const int mod = 1000000007;
        vector<vector<long long>>dp(n+5,vector<long long>(m+5,-1));

        auto add = [&](long long a,long long b)->long long{
            a+=mod;
            b+=mod;
            return ((a%mod)+(b%mod))%mod;
        };
        auto mul = [&](long long a,long long b)->int{
            return ((a%mod)*(b%mod))%mod;
        };

        auto solve = [&](auto&self,int idx,int c)->long long{
            if(idx==n)return 1;
            if(m-c<n-idx)return 0;
            auto &ret = dp[idx][c];
            if(ret!=-1)return ret;
            ret = self(self,idx,c+1);
            if(col[c][target[idx]-'a']){
                ret =  add(ret,mul(col[c][target[idx]-'a'],self(self,idx+1,c+1)));
            }
            return ret;
        };

        return solve(solve,0,0)%mod;
    }
};