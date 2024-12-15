class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        long long ans = 1LL<<36;
        long long nn = n;
        do{
            //cout<<s<<"\n";
            if(stoll(s)>nn)
                ans  = min(ans,stoll(s));
        }while(next_permutation(s.begin(),s.end()));
        if(ans ==(1LL<<36) or (ans > INT_MAX))ans = -1;
        return ans;
    }
};