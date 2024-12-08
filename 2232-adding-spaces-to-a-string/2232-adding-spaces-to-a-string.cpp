class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ret ;
        sort(spaces.rbegin(),spaces.rend());
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(spaces.size()&&i==spaces.back()){
                spaces.pop_back();
                ret+=" ";
            }
           
            ret+=s[i];
        }

        return ret;
    }
};