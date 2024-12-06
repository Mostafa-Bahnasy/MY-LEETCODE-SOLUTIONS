class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        const int N = 1e4+10;

        bool vis[N] = {};
        for(auto&i:banned){
            vis[i] = true;
        }
        int sum = 0, cnt = 0;
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                if(sum+i<=maxSum){
                    sum+=i;
                    cnt++;
                }else break;
            }
        }

        return cnt;
    }
};