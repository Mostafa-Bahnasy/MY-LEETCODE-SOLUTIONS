class Solution {
public:
    string minWindow(string s, string t) {
        int tar[130] = {};
        for(auto&i:t)tar[int(i)]++;

        int cnt[130] ={};

        auto check =[&](int i)->bool{
            return (tar[i]&&cnt[i]>tar[i])||tar[i]==0;
        };
        
        auto is_valid =[&]()->bool{
            for(int i = 0;i<130;i++){
                if(cnt[i]<tar[i])return false;

            }
            //cout<<cnt[int('a')] <<" - "<<tar[int('b')]<<"\n";
            return true;
        };
        int l = 0 ,r = 0,n = s.size();
        int ans = 1e9 , lq = 0, rq = 0;
        while(r<n){
            cnt[int(s[r])]++;
            //cout<<l<<" "<<r<<"\n";
            
            if(check(int(s[l]))){
                //cout<<"r: "<<r<<"\n";
                while(l<=r&&check(int(s[l]))){
                    cnt[int(s[l])]--,l++;
                    cout<<"he- ";
                }
                //cnt[int(s[l])]--,l++;
                //cout<<"L: "<<l<<"\n";
            }
            //cout<<"here\n";
            //cnt[int(s[l])]++;

            if(is_valid()&&ans>r-l+1){
                ans  = r-l+1;
                lq = l , rq = r;
            }
            r++;
            r = max(r,l);
        }
        if(ans==1e9)ans = 0;
        return s.substr(lq,ans);
    }
};