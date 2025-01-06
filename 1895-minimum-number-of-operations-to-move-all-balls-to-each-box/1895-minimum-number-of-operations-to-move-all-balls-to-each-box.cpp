class Solution {
public:
    vector<int> minOperations(string box) {
        int n = box.size();
        vector<int>prf(n),suf(n);
        int c = 0;
        for(int i = 0;i<n;i++){
            if(i)
                prf[i] = prf[i] + c+prf[i-1];
            if(box[i]=='1'){
                c++;
            }
        }
        c = 0;
        for(int i = n-1;i>-1;i--){
            if(i<n-1)
                suf[i] = suf[i] + c+suf[i+1];
            if(box[i]=='1'){
                c++;
            }
            // cout<<suf[i]<<"\n";
        }
        
        vector<int>ret(n);
        for(int i  = 0;i<n;i++){
            
            ret[i] = suf[i] + prf[i];


        }

        return ret;
    }
};