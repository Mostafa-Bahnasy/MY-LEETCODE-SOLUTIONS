class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newInterval) {

        v.insert(v.begin(),newInterval);
        sort(v.begin(),v.end());
        for(int i = 0;i<-1+v.size();i++){
            if(v[i][0]<=v[i+1][0]&&v[i][1]>=v[i+1][0]){
                v[i][0] = min(v[i][0],v[i+1][0]);
                v[i][1] = max(v[i][1],v[i+1][1]);
                v.erase(v.begin()+1+i);
                // break;
                i--;
            }
        }
        return v;
    }
};