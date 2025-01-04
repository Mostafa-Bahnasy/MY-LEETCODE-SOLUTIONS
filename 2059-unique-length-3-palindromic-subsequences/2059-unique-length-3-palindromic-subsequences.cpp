class segTree{
    int sz;
    vector<bitset<26>>tree;
    public:
    segTree(string&s,int n){
        tree.resize(n*4);
        build(1,0,n-1,s);
    };

    void build(int idx,int l ,int r,string&s){
        if(l==r){
            return tree[idx][s[l]-'a'] = true,void();
        }

        int md = (l+r)/2;
        build(idx*2,l,md,s);
        build(idx*2+1,md+1,r,s);
        tree[idx] = tree[idx*2] | tree[idx*2+1];
    }

    bitset<26> query(int idx,int l,int r,int lc,int rc){
        if(l>rc or r<lc)return {};
        if(lc<=l&&r<=rc)return tree[idx];
        int md= (l+r)/2;
        return query(idx*2,l,md,lc,rc) | query(idx*2+1,md+1,r,lc,rc);
    }

};

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // vector<string>pal;
        // for(char a = 'a';a<='z';a++){
        //     for(char b = 'a';b<='z';b++){
        //         string tmp;
        //         tmp +=a;
        //         tmp+=b;
        //         tmp+=a;
        //         pal.push_back(tmp);
        //     }   
        // }

        int r[26] = {};
        vector<int>l(26,s.size());
        for(int i = 0;i<s.size();++i){
            short cur = s[i]-'a';
            r[cur] = i;
            if(l[cur]==s.size())l[cur] = i;
        }
        segTree st(s,s.size());
        int ans = 0;
        for(int i = 0;i<26;i++){
            auto rr = r[i];
            auto ll = l[i];
            if(!(ll+1<rr))continue;
            // cout<<ll<<" "<<rr<<"\n";
            ans+=st.query(1,0,s.size()-1,ll+1,rr-1).count();
        }
        return ans;
    }
};