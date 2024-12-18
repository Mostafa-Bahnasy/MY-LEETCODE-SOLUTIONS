class Solution {
public:
    vector<int> finalPrices(vector<int>& v) {
        stack<int>st;
        int n = v.size();
        
        for(int i =n-1;i>-1;i--){
            while(st.size()&&st.top()>v[i])st.pop();
            int nw = v[i];
            if(st.size()){
                nw = v[i]-st.top();
            }
            st.push(v[i]);
            v[i] = nw;
        }

        return v;
    }
};