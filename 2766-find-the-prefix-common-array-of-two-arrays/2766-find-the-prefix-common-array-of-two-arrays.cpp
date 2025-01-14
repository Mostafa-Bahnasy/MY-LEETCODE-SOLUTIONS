class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>cnt(n+1);

        int ans = 0;
        vector<int>ret(n);
        for(int i = 0;i<n;i++){
            cnt[A[i]]++;
            cnt[B[i]]++;

            if(cnt[A[i]]==2)ans++;
            if(A[i]!=B[i] and cnt[B[i]]==2)ans++;
            ret[i] = ans;
        }
        return ret;
    }
};