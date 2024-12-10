class Solution {
public:
    int maximumLength(string s) {
        
        int ans = -1;
        int n = s.size();
        for(int len = 1;len<=n;len++){
            unordered_map<string , int>cnt;
            for(int i = 0;i+len-1<n;i++){
                bool is = true;
                for(int j = i;j<=i+len-1;j++){
                    if(s[j]!=s[i]){is = false;break;}
                }
                if(is)
                    cnt[s.substr(i,len)]++;
            }
            for(auto&[ss,c]:cnt){
                if(c>2){
                    cout<<ss<<"\n";
                    ans = len;
                    break;
                }
            }
        }
        return ans;
    }
};