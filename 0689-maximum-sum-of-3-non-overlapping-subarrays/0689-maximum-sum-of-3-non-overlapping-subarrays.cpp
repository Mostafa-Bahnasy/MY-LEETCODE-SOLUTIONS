class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int>sum(n+2);
        sum[0] = nums[0];
        for(int i = 1;i<n;i++){
            sum[i]=nums[i]+sum[i-1];
        }

        vector<int>prf(n+2),suf(n+2),prfmx(n+2),sufmx(n+2);
        int mx = 0;
        for(int i = 0;i+k-1<n;i++){
            if(i==0)
                prf[i] = i,mx= sum[i+k-1];
            else{
                if(sum[i+k-1]-sum[i-1]>mx){
                    prf[i] = i;
                    mx = sum[i+k-1]-sum[i-1];
                }else prf[i] = prf[i-1];
            }
            prfmx[i] = mx;
        }
        mx = 0;
        for(int i = n-k;i>0;i--){
            if(i==0){
                if(mx<=sum[i+k-1]){
                    suf[i] = i;
                    mx = sum[i+k-1];
                }else suf[i]  = suf[i+1];
            }else{
                if(mx<=sum[i+k-1]-sum[i-1]){
                    mx = sum[i+k-1]-sum[i-1];
                    suf[i] = i;
                }else suf[i] = suf[i+1];
            }
            sufmx[i]  = mx;
        }

        mx = 0;
        vector<int>ret(3);
        for(int i = k;i+2*k-1<n;i++){
            // cout<<prfmx[i-k]<<" "<<(sum[i+k-1]-sum[i-1])<<" "<<sufmx[i+k]<<"\n";
            if(mx<prfmx[i-k] + sufmx[i+k] + (sum[i+k-1]-sum[i-1])){
                ret = {prf[i-k],i,suf[i+k]};
                mx = prfmx[i-k] + sufmx[i+k] + (sum[i+k-1]-sum[i-1]);
            }
        }
        return ret;
        
    }
};