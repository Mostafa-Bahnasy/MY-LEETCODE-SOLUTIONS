class segTree{
    int sz;
    struct node{
        int mn = 1000000000;
        int mx = 0;
        int df = 0;
    };
    vector<node>tree;

public:
    segTree(int n){
        tree.resize(n*4);
        sz = n;   
    }

    node merge(node left,node right){
        node ret = {min(left.mn,right.mn),max(left.mx,right.mx),max({left.df,right.df,right.mx-left.mn})};
        return ret;
    }
    void upd(int idx,int l, int r,int pos,int val){
        if(l>pos or r<pos)return ;
        if(l==r){
            tree[idx].mn = val;
            tree[idx].mx = val;
            return;
        }

        int md =( l+r)/2;
        upd(idx*2,l,md,pos,val);
        upd(idx*2+1,md+1,r,pos,val);

        tree[idx]  = merge(tree[idx*2],tree[idx*2+1]);
    }

    node query(int idx,int l, int r,int lc,int rc){
        if(l>rc||r<lc)return {1000000000,0,0};
        if(lc<=l&&r<=rc){
            return tree[idx];
        }
        int md = (l+r)/2;
        auto left = query(idx*2,l,md,lc,rc);
        auto right = query(idx*2+1,md+1,r,lc,rc);

        return merge(left,right);
    }

};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // seg -> max, min, df
        int n= prices.size();

        segTree st(n);
        for(int i =0;i<n;i++){
            st.upd(1,0,n-1,i,prices[i]);
        }
        int ans = 0;
        for(int i =1;i<n-1;i++){
            // 0,1 
            int prf = st.query(1,0,n-1,0,i).df;
            int suf = st.query(1,0,n-1,i+1,n-1).df;
            ans = max(ans,prf+suf);
        }
        return max(ans,st.query(1,0,n-1,0,n-1).df);

    }
};