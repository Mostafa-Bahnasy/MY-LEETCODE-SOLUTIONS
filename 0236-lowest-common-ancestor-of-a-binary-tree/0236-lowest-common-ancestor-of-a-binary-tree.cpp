/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        bool is = true;
        auto dfs =[&](auto&self,TreeNode* node)->pair<bool,bool>{
            if(node == nullptr)return{0,0};
            pair<bool,bool>ret = {};
            
            auto left = self(self,node->left);
            auto right = self(self,node->right);
            ret.first = left.first or right.first;
            ret.second =left.second or right.second;
            
            if(node->val==p->val)ret.first = true;
            if(node->val==q->val)ret.second = true;

            if(is&&ret.first==true&&ret.second==true)ans = node,is = false;
            return ret;
        };
        dfs(dfs,root);
        return ans;
    }
};