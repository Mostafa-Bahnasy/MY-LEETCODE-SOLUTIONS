class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
    std::priority_queue<std::tuple<double, int, int>> pq;

        for(auto&v:classes){
            // int gc = gcd(v[0],v[1]);
            // v[0] = (v[0]/gcd(v[0],v[1]));
            // v[1] = (v[1]/gcd(v[0],v[1]));
            //cout<<v[0]<<" "<<v[1]<<"\n";
            pq.push({(1.0*(v[0]+1)/(v[1]+1))-(1.0*v[0]/v[1]),v[0],v[1]});
        }

        while(extra&&pq.size()){
            auto [rat,a,b] = pq.top();
            pq.pop();

            double r = 1.0*(a+1)/(b+1);
            pq.push({(1.0*(a+2)/(2+b))-r,a+1,b+1});
            extra--;
        }

        double avg = 0;
        while(pq.size()){
            auto [rat,a,b] = pq.top();
            pq.pop();
            avg+=(1.0*a/b);
        }


        return avg/classes.size();
    }
};