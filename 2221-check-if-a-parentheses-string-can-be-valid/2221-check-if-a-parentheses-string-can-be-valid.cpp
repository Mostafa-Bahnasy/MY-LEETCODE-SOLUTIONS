class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        int open = 0;
        int can = 0;

        for(int i = 0;i<s.size();i++){
            if(locked[i]=='1'){
                if(s[i]=='(')open++;
                else{
                    if(open>0)open--;
                    else if(can>0){
                        can--;
                        open++;
                    }else return false;
                }
            }else{
                if(open>0){
                    open--;
                    can++;
                }else{
                    open++;
                }
            }
        }
        return open==0;
    }
};
