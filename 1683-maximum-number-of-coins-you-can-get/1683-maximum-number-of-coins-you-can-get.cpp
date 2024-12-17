class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int ans = 0;

        int l = 0, r = piles.size()-1;

        while(l<r){
            ans+=piles[r-1];
            l++;
            r-=2;
        }
        return ans;
    }
};