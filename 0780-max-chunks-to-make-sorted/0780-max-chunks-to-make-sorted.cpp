class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ret=0,sum =0 ;
        for(int i =  0;i<arr.size();i++){
            sum+=arr[i]-i;
            ret+=(sum==0);
        }
        return ret;
    }
};