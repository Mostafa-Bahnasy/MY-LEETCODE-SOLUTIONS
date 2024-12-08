class Solution {
public:
    int isPrefixOfWord(string s, string tar) {
        s +=" ";
        string tmp;
        int idx = 1;
        for(auto&i:s){
            if(i==' '){
                bool ret  = true;
                for(int j = 0;j<tar.size();j++){
                    if(j==tmp.size()||tmp[j]!=tar[j]){ret = false;break;}
                }
                if(ret)return idx;
                idx++;
                tmp = "";
            }else tmp+=i;
        }
        return -1;
    }
};