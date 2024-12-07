class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        int l = 0 , r= 0;
        while(l<n&&r<m){
            if(str1[l]==str2[r]||(((1+(str1[l]-'a'))%26)+'a') == str2[r]){
                r++,l++;
            }else{
                l++;
            }
        }
        return r == m;
    }
};