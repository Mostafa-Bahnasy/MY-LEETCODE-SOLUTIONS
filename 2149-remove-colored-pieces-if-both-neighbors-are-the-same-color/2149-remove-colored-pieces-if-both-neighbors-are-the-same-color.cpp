class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt = 0;
        for(int i = 0;i<colors.size();i++){
            int j = i;
            while(j<colors.size()&&colors[j]==colors[i])j++;
            if(colors[i] == 'A')cnt = cnt + max(0,j-i-2);
            else cnt = cnt - max(0,j-i-2);
            i = j-1;
        }

        return cnt>0;
    }
};