/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minSwaps(vector<int>nums, int n)
    {
        int len = n;
        map<int, int> map;
        for (int i = 0; i < len; i++)
            map[nums[i]] = i;

        sort(nums.begin(), nums.end());

        // To keep track of visited elements. Initialize
        // all elements as not visited or false.
        vector<int> visited(len) ;

        // Initialize result
        int ans = 0;
        for (int i = 0; i < len; i++) {

            // already swapped and corrected or
            // already present at correct pos
            if (visited[i] || map[nums[i]] == i)
                continue;

            int j = i, cycle_size = 0;
            while (!visited[j]) {
                visited[j] = true;

                // move to next node
                j = map[nums[j]];
                cycle_size++;
            }

            // Update answer by adding current cycle.
            if (cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        int mx = 0;
        auto dfs = [&](auto&self,TreeNode* node,int lvl = 0)->void{
            if(node==nullptr)return;
            mx = max(mx,lvl);
            self(self,node->left,lvl+1);
            self(self,node->right,lvl+1);
        };


        dfs(dfs,root);
        vector<vector<int>>v(mx+1);

        auto build = [&](auto&self,TreeNode* node,int lvl = 0)->void{
            if(node==nullptr)return;
            //mx = max(mx,lvl);
            v[lvl].push_back(node->val);
            self(self,node->left,lvl+1);
            self(self,node->right,lvl+1);
        };
        build(build,root);

        auto calc = [&](vector<int>&v)->int{
            int n= v.size();
            auto tmp = v;
            sort(tmp.begin(),tmp.end());
            unordered_map<int,int>idx ;
            for(int i = 0;i<n;i++){
                idx[tmp[i]] = i;
            }
            int ret = 0;
            for(int i = 0;i<n;i++){
                cout<<v[i]<<"  - "<<tmp[i]<<"\n";
                if(v[i]!=tmp[i]){
                    ret ++;
                    int old = v[i];
                    cout<<idx[v[i]]<< " + "<<idx[tmp[i]]<<"\n";
                    swap(v[idx[v[i]]],v[idx[tmp[i]]]);

                    idx[old] = idx[tmp[i]];
                    idx[tmp[i]] = i;
                }
                for(auto&j:v)cout<<j<<" ";cout<<"\n";
            }
            return ret;
        };
        int ans  =0;
        for(int i = 0;i<mx+1;i++){
            //for(auto&j:v[i])cout<<j<<" ";cout<<"\n";
            ans+=minSwaps(v[i],v[i].size());
        }
        return ans;
    }
};