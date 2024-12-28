class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = -100000;
        int mx = 0;
        for(int i = 0;i<values.size();i++){
            ans = max(ans,mx+values[i]-i);
            mx = max(mx,values[i]+i);
        }
        return ans;
    }
};