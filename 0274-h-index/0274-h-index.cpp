class Solution {
public:
    int hIndex(vector<int>& nums) {
        const int N = 1e3+5;
        int suf[N] = {};
        for(auto&i:nums)suf[i]++;
        for(int i = N-2;i>-1;i--)suf[i] +=suf[i+1];
        int ans = 0;
        for(int i =0;i<N-1;i++){
            ans = max({ans,(suf[i]-suf[i+1]>= i)?i:0,(suf[i]>= i)?i:0});
        }
        return ans;
    }
};