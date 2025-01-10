struct TinyInt {
    unsigned int value :12  = 0; // 3 bits, can store values 0-7
};


class Solution {
public:
    int maxLength(vector<int>& nums) {
        int  ret = 1;
        auto calc = [&](int l ,int r)->void{
            TinyInt gc;
            TinyInt lc;
            TinyInt prod;
            lc.value = 1;
            prod.value = 1;
            for(int i = l;i<=r;i++){
                TinyInt tmp;
                tmp.value = nums[i];
                gc.value = gcd(gc.value,tmp.value);
                lc.value = lcm(lc.value,tmp.value);
                prod.value = prod.value*tmp.value;
            }
            if(prod.value ==gc.value*lc.value ){
                // cout<<"L: "<<l<< " "<<"R: "<<r<<"\n";
                if(ret<r-l+1)ret = r-l+1;
            }

        };

        for(int i = 0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                calc(i,j);
            }
        }
        return ret;
    }
};