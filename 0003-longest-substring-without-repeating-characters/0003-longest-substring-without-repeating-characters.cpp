class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0 ,r = 0;
        bitset<130>bt;
        int ans = 0;
        while(r<n){

            if(bt[int(s[r])]){
                while(l<r&&s[l]!=s[r]){
                    bt[int(s[l])] = false;
                    l++;
                }
                bt[int(s[l])] = false;
                l++;
            }
            bt[int(s[r])]= true;
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};