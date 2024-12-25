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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ret;
        // cout<<ret.size()<<"\n";
        const int MN = -(1<<31);
        auto dfs = [&](auto&self,TreeNode*node,int lvl = 0)->void{
            if(node == nullptr)return;
            // cout<<ret.size() -1 <<" "<<lvl<<"\n";
            while(int(ret.size())-1<lvl){
                ret.push_back(MN);
                // cout<<"ADDED\n";    
            }
            // cout<<"HR\n";
            ret[lvl] = max(ret[lvl],node->val);

            self(self,node->left,lvl+1);
            self(self,node->right,lvl+1);
        };

        dfs(dfs,root);
        return ret;
    }
};