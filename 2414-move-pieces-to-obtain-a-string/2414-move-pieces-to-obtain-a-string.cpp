class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();

        int l = 0, r = 0;
        while(l<n&&r<n){
            while(r<n&&target[r]=='_')r++;
            if(r==n)break;
            while(l<n&&start[l]=='_')l++;
            if(l==n)break;
            char tar = target[r];
            
            if(start[l]!=tar)break;
            else{
                if(tar=='R'&&l>r)return false;
                if(tar=='L'&&l<r)return false;
            }
            l++,r++;
        }
        while(l<n&&start[l]=='_')l++;
        while(r<n&&target[r]=='_')r++;

        if(l==n&&r==n)return true;
        else return false;
    }
};