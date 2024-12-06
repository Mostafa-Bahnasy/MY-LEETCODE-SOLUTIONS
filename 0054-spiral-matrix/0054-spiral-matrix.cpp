class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ret;
        int n = matrix.size();
        int m = matrix[0].size();
        int dy[] = {1,0,-1,0};
        int dx []= {0,1,0,-1};

        int x = 0 ,y = 0,idx = 0;
        while (true){
            //cout<<"Here\n";
            //cout<<"X: "<<x<< "Y: "<<y<<"\n";
            bool trig = true;
            while(x>-1&&y>-1&&x<n&&y<m&&matrix[x][y]!=-200){
                ret.push_back(matrix[x][y]);
                matrix[x][y] = -200;
                x+=dx[idx];
                y+=dy[idx];

                trig = false;
            }
            if(trig)break;
            x+=-dx[idx];
            y+=-dy[idx];
            idx = (idx + 1)%4;
            
            x+=dx[idx];
            y+=dy[idx];
        }

        return ret;
    }
};