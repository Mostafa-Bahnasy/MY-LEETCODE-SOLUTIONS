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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        auto calc =[&](vector<int>&v)->int{
            int ret = 0;
            long long base = 1;
            for(int i =v.size()-1;i>-1;i--){
                //cout<<v[i]<<" - ";
                ret+=v[i]*base;
                base*=10;
            }
            //cout<<"\n";
            return ret;
        };
        auto dfs = [&](auto&self,TreeNode* node,vector<int>&v) ->void{
            v.push_back(node->val);
            if(node->left == nullptr&&node->right == nullptr){
                ans+=calc(v);
                v.pop_back();
                return;
            }
            if(node->left!=nullptr)
                self(self,node->left,v);
            if(node->right!=nullptr)
                self(self,node->right,v);
            
            v.pop_back();
            
        };
        vector<int>tmp;
        dfs(dfs,root,tmp);
        return ans;
    }
};