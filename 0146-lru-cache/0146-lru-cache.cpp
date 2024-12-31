class LRUCache {
public:
    int k[10005] ={};
    int idx[10005] ={};
    vector<int>w;
    set<pair<int,int>>used;
    // vector<int>idx;
    vector<int>bt;
    int sz;
    int ptr = 0;
    int cap = 1;
    LRUCache(int capacity) {
        sz = capacity;
        for(int i = 0;i<10002;i++){
            k[i] = -1;
        }
    }
    
    int get(int key) {
        if(k[key]!=-1)
            bt[idx[key]] = cap++;
        return k[key];
    }
    
    void put(int key, int value) {
        cout<<"HERE\n";
        if(k[key]==-1){ // not encountered
            // cout<<"H\n";
            if(w.size()<sz){ // place
                idx[key] = w.size();
                w.push_back(key);
                bt.push_back(cap++);
                k[key] = value;
                ptr++;

            }else{ // replace
                int mn = *min_element(bt.begin(),bt.end());
                while(bt[ptr]!=mn){
                    // bt[ptr]--;
                    ptr++;
                    ptr%=sz;
                }
                cout<<w[ptr]<<"\n";
                idx[w[ptr]] = -1;
                k[w[ptr]] = -1;
                bt[ptr] = cap++;
                idx[key] = ptr;
                k[key] = value;
                w[ptr] = key;
                ptr++;
            }
        }else{
            bt[idx[key]] = cap++;
            k[key] = value;
        }
        ptr%=sz;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */