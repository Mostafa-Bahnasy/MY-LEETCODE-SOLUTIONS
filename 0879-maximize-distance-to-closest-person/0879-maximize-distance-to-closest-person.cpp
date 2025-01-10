struct TinyInt {
    unsigned int value :8  = 0; // 10 bits, can store values 0-1023
};



class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        TinyInt c;
        int ans;
        bool is = true;
        for(auto&i:seats){
            if(i){
                if(!is)
                    ans = max(ans,(c.value+1)/2);
                else
                    ans = max(ans,1*c.value);

                c.value=0;
                is = false;
            }else{
                c.value++;
            }
        }
        ans = max(ans,1*c.value);
        return ans;
    }
};