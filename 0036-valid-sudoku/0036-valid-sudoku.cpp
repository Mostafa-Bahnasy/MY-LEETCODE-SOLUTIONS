class Solution {
public:
    inline bool checkRow(vector<vector<char>>&v,int row){
        int vis [10] = {};
        for(int i = 0;i<9;i++){
            if(isdigit(v[row][i])){
                //cout<<row<<" "<<i<<"\n"; 
                vis[int(v[row][i]-'0')]++;
                if(vis[int(v[row][i]-'0')] > 1)return false;
            }
        }
        return true;
    }
    inline bool checkCol(vector<vector<char>>&v,int col){
        int vis [10] = {};
        for(int i = 0;i<9;i++){
            if(isdigit(v[i][col])){
                vis[int(v[i][col]-'0')]++;
                if(vis[int (v[i][col]-'0')] > 1)return false;
            }
        }
        return true;
    }
    
    inline bool checkWindow(vector<vector<char>>&v,int r,int c){
        int vis [10] = {};
        
        for(int dx = -1;dx<2;dx++)
            for(int dy = -1;dy<2;dy++){
                if(isdigit(v[r+dx][c+dy])){
                        
                    vis[int(v[r+dx][c+dy]-'0')]++;
                    if(vis[int(v[r+dx][c+dy]-'0')] > 1)return false;
                }
            }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool is = true;
        int n = 9;
        for(int i = 0;i<n;i++){
            is&=checkRow(board,i);
        }
        if(!is)return false;
        for(int i = 0;i<n;i++){
            is&=checkCol(board,i);
        }
        if(!is)return false;
        for(int i = 1;i<n;i+=3){
            for(int j = 1;j<n;j+=3)
                is&=checkWindow(board,i,j);  
        }
        return is;

    }
};