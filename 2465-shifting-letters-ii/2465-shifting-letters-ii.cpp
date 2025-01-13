class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        std::vector<int>prf(n+2);
        for(auto qu:shifts){
            if(qu[2]==1){
                prf[qu[0]] +=1;
                prf[qu[1]+1]-=1;
            }else{
                
                prf[qu[0]] -=1;
                prf[qu[1]+1]+=1;
            }
        }

        for(int i = 1;i<=n;i++)prf[i]+=prf[i-1];
        for(int i = 0;i<n;i++){
            int ch = int(s[i]-'a') + prf[i];
            while(ch<0)ch+=26;
            ch%=26;
            s[i] = char(ch+'a');
        }
        return s;
        
    }
};