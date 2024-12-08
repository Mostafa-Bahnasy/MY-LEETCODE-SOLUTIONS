class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        auto cmp = [&](vector<int> a,vector<int> b)->bool{
            return a[1]<b[1];
        };

        sort(v.begin(),v.end(),cmp);
        int n = v.size();
        int ans = 1;
        int lst = v[0][1];

        for(int i = 1;i<n;i++){
            if(v[i][0]<=lst){
                continue;
            }else{
                ans++;
                lst = v[i][1];
            }
        }
        return ans;
    }
};