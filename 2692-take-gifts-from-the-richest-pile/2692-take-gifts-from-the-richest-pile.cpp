class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(auto&i:gifts)pq.push(i);

        long long ans = 0;
        while(k--&&pq.size()){
            auto tp = pq.top();
            pq.pop();
            //ans += 1LL*(tp-(int)sqrtl(tp));
            tp = int(sqrtl(tp));
            if(tp)
                pq.push(tp);
        }
        while(pq.size()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};