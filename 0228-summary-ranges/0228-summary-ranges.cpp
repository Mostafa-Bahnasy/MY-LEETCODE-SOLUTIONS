class Solution {
public:
    vector<string> summaryRanges(vector<int>& v) {
        vector<string>ret;
        int n = v.size();
        for(int i = 0;i<n;i++){
            int j = i;
            while(j<n&&1LL*v[j]-v[i]==1LL*j-i)j++;
            //cout<<j<<"\n";
            if(abs(1LL*j-i)<2){
                ret.push_back(to_string(v[i]));
            }else{
                ret.push_back(to_string(v[i])+"->"+to_string(v[j-1]));
            }
            i = j-1;
        }
        return ret;
    }
};