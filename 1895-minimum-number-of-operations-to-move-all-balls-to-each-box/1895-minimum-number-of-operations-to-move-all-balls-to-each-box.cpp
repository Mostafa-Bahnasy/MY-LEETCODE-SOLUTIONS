class Solution {
public:
    vector<int> minOperations(string box) {
        int n = box.size();
        vector<int>prf(n);
        int c = 0;
        for(int i = 0;i<n;i++){
            if(i)
                prf[i] = prf[i] + c+prf[i-1];
            if(box[i]=='1'){
                c++;
            }
        }
        c = 0;
        int suff = 0;
        vector<int>ret(n);
        for(int i = n-1;i>-1;i--){
            if(i<n-1)
                suff =c+suff;
            if(box[i]=='1'){
                c++;
            }
            ret[i] = suff + prf[i];
        }
        

        return ret;
    }
};