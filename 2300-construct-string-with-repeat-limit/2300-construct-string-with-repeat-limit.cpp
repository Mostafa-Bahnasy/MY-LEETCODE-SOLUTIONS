class Solution {
public:
    string repeatLimitedString(string ss, int lim) {
        
        int cnt[26] = {};
        for(auto&i:ss){
            cnt[i-'a']++;
        }
        string s;
        auto get = [&](int ch)->int{
            for(int i = ch;i>-1;i--){

                if(cnt[i]>0)return i;
            }
            return -1;
        };
        auto solve =[&](int ch)->void{

            while(cnt[ch]>0){
                //cout<<cnt[ch]<<" "<<ch<<"\n";
                int del = min(cnt[ch],lim);
                cnt[ch]-=del;
                s+=string(del,char(ch+'a'));
                if(cnt[ch]>0){
                    //cout<<"here\n";
                    auto p = get(ch-1);
                    //cout<<ch<<" "<<p<<"\n";
                    if(p==-1)return;
                    s+=char(p+'a');
                    cnt[p]--;
                } 
            }
            
        };

        for(int i = 25;i>-1;i--)
            if(cnt[i]>0)
                solve(i);

        return s;
    }
};