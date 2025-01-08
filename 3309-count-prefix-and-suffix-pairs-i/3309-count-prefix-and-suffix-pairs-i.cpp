class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        
        auto calc = [&](string a,string b)->int{
            if(a.size()>b.size())return 0;
            int l = 0, r = 0;
            while(l<a.size() and r < b.size()){
                if(a[l]!=b[r])return 0;
                l++,r++;
            }
            l = a.size()-1,r = b.size()-1;
            while(l>-1 and r > -1){
                if(a[l]!=b[r])return 0;
                l--,r--;
            }
            return 1;
        };
        int ans = 0;
        for(int i = 0;i<words.size();i++){
            for(int j = i+1;j<words.size();j++){
                ans += calc(words[i],words[j]);
            }
        }
        return ans;
    }
};