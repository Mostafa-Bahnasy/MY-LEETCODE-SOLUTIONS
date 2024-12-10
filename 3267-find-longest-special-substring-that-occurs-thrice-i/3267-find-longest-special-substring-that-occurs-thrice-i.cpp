class Solution {
public:
    int maximumLength(string s) {
        
        int ans = -1;
        int n = s.size();
        int l = 1 , r = n;
        while(l<=r){
            int len = (l+r)/2;
            unordered_map<string , int>cnt;
            for(int i = 0;i+len-1<n;i++){
                bool is = true;
                for(int j = i;j<=i+len-1;j++){
                    if(s[j]!=s[i]){is = false;break;}
                }
                if(is)
                    cnt[s.substr(i,len)]++;
            }
            bool can = false;
            for(auto&[ss,c]:cnt){
                if(c>2){
                    cout<<ss<<"\n";
                    ans = len;
                    can = true;
                    break;
                }
            }
            if (can == true)l = len+1;
            else r= len-1;
        }
        return ans;
    }
};