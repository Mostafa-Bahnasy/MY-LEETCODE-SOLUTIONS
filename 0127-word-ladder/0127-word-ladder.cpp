class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<int>>all;
        unordered_map<string,int>idx;

        wordList.push_back(endWord);
        wordList.insert(wordList.begin(),beginWord);
        for(int i = 0;i<wordList.size();i++){
            // if(idx.count(wordList[i]))continue;
            idx[wordList[i]] = i;
        }
        for(int i = 1;i<wordList.size()-1;i++){
            auto id = idx[wordList[i]];
            auto s = wordList[i];
            
            for(int i= 0;i<s.size();i++){
                char old = s[i];
                s[i] = '#';
                all[s].push_back(id);
                s[i] = old;
            }
            // i++;
        }

        // queue<int>q;

        vector<int>dst(wordList.size()+5,-1);
        dst[idx[beginWord]] = 1;
        queue<int>q;
        q.push(idx[beginWord]);
        while(q.size()){
            auto id = q.front();
            q.pop();
            // cout<<s<<"\n";
            string s = wordList[id];
            if(s==endWord){
                return dst[id];
            }
            int d = dst[id];
            for(int i = 0;i<s.size();i++){
                char old = s[i];
                s[i] = '#';

                for(auto&to:all[s]){
                    if(dst[to]!=-1)continue;
                    dst[to] = d+1;
                    q.push(to);
                }
                s[i] = old;
            }

        }
        return 0;

    }
};