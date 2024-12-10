class Solution {
public:
    int maximumLength(string s) {
        
        int ans = -1;
        int n = s.size();
        int l = 1 , r = n;
        while(l<=r){
            int len = (l+r)/2;
            int count[26] = {};
            for(int i = 0;i<n;i++){
                int cnt = 0;
                int j = i;
                while(j<n&&s[j]==s[i])cnt++,j++;

                if(cnt>=len){
                    count[(s[i]-'a')]+=(cnt-len+1);
                }
                i = j-1;
            }
            //cout<<len<<" " <<*max_element(count,count+26)<<"\n";
            bool can = (*max_element(count,count+26)>2);
            
            if (can == true)l = len+1,ans=len;
            else r= len-1;
        }
        return ans;
    }
};