class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newInterval) {
        sort(v.begin(),v.end());

        v.insert(v.begin(),newInterval);
        sort(v.begin(),v.end());
        for(int i = 0;i<-1+v.size();i++){
            if(v[i][0]<=v[i+1][0]&&v[i][1]>=v[i+1][0]){
                vector<int>tmp(2);
                tmp[0]= min(v[i][0],v[i+1][0]);
                tmp[1] = max(v[i][1],v[i+1][1]);
                v.erase(v.begin()+i);
                v.erase(v.begin()+i);
                v.insert(v.begin()+i,tmp);
                // break;
                i = -1;
            }
        }
        sort(v.begin(),v.end());

        return v;
    }
};