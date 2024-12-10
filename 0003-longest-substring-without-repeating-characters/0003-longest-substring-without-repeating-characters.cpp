class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 1,r = 130;
        int ans  = 0;
        int n = s.size();
        while(l<=r){
            int len = (l+r)/2;
            bool can = false;
            for(int i = 0;i+len-1<n;i++){
                bitset<130>bt;
                bool is = true;
                for(int j = i;j<i+len;j++){
                    if(bt[int(s[j])]){
                        is = false;break;
                    }
                    bt[int(s[j])] = true;
                }
                if(is){can = true;break;}
            }

            if(can) ans = len, l = len+1;
            else r = len-1;
        }
        return ans;
    }
};