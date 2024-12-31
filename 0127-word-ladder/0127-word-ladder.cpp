class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,set<string>>all;
        
        for(auto&s:wordList){
            auto ss = s;
            for(int i= 0;i<s.size();i++){
                ss[i] = '#';
                all[ss].insert(s);
                ss[i] = s[i];
            }
        }

        // queue<int>q;

        unordered_map<string,int>dst;
        dst[beginWord] = 1;

        queue<string>q;
        q.push(beginWord);
        while(q.size()){
            auto s = q.front();
            q.pop();
            // cout<<s<<"\n";
            if(s==endWord){
                return dst[s];
            }
            int d = dst[s];
            for(int i = 0;i<s.size();i++){
                char old = s[i];
                s[i] = '#';

                for(auto&to:all[s]){
                    if(dst.count(to))continue;
                    dst[to] = d+1;
                    q.push(to);
                }
                s[i] = old;
            }

        }
        return 0;

    }
};