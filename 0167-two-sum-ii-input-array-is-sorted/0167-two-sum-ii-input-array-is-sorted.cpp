class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        for(int i = 0;i<numbers.size();i++){
            int need = target - numbers[i];
            int l = 0 ,r = i-1;
            int idx = -1;
            while (l<=r){
                int md = (l+r)/2;
                if(numbers[md]<need){
                    l = md+1;
                }else if(numbers[md]>need){
                    r = md-1;
                }else {idx = md;break;}
            }
            if(idx!=-1)return {idx+1,i+1};
            l = i+1, r = numbers.size()-1;
            while (l<=r){
                int md = (l+r)/2;
                //cout<<md<<"\n";
                if(numbers[md]<need){
                    l = md+1;
                }else if(numbers[md]>need){
                    r = md-1;
                    //cout<<"here\n";
                }else {idx = md;break;}
            }
            cout<<"\n";
            if(idx!=-1)return {i+1,idx+1};

        }
        return {};
    }
};