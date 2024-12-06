class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n = s.size();
        int base = words[0].size();
        int len = base*words.size();
        vector<int>ret;
        if(base == 1){
            int vis[26] = {};
            for(auto&i:words)vis[int(i[0]-'a')]++;
            for(int i = 0;i+len-1<n;i++){
                int have[26] = {};
                bool is = true;
                for(int j = i;j<i+len;j+=base){
                    int tmp = int(s.substr(j,base)[0]-'a');
                    have[tmp]++;
                    if(have[tmp]>vis[tmp]){
                        is = false;break;
                    }
                }
                if(is)ret.push_back(i);
            }
        }else{
            std::unordered_map<string,short>vis;
            for(auto&i:words)vis[i]++;
            for(int i = 0;i+len-1<n;i++){
                std::unordered_map<string,short>have;
                bool is = true;
                for(int j = i;j<i+len;j+=base){
                    string tmp = s.substr(j,base);
                    have[tmp]++;
                    if(have[tmp]>vis[tmp]){
                        is = false;break;
                    }
                }
                if(is)ret.push_back(i);
            }
        }
        
        return ret;
    }
};