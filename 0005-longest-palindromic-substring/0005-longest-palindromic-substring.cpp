class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();

        auto solve =[&](int l,int r)->int{

            while(l>-1&&r<n){
                if(s[l]==s[r])r++,l--;
                else break;
            }
            return r-l-1;
        };
        int len = 1;
        int id = 0;
        for(int i = 0;i<n;i++){
            int g = solve(i,i);
            if(g>len){
                len = g;
                id = i-g/2;
            }

            if(i<n&&s[i]==s[i+1]){
                g = solve(i,i+1);
                if(g>len){
                    len = g;
                    id = i-(g-1)/2;
                }
            }
        }

        return s.substr(id,len);
    }
};