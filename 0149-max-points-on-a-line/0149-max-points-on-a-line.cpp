class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        auto Slope =[&](vector<int>&a,vector<int>&b)->tuple<int,int,int,int>{
            tuple<int,int,int,int>ret = {b[1]-a[1],b[0]-a[0],a[0],a[1]};
            return ret;
        };
        int n = points.size();
        vector<tuple<int,int,int,int>>slps;
        for(int i = 0;i<n;i++){
            for(int j =i+1;j<n;j++){
                slps.push_back(Slope(points[i],points[j]));
            }
        }
        int ret = 1;

        for(auto&[up,down,x_src,y_src]:slps){
            int cnt = 0;
            for(int i = 0;i<n;i++){
                int x = points[i][0];
                int y = points[i][1];
                if((y-y_src)*down == up *(x-x_src))cnt++;
            }
            ret = max(ret,cnt);
        }
        return ret;
    }
};