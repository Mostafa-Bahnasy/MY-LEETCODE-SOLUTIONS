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
    int maxDepth(TreeNode* root) {
        int ans = -1;
        
        auto dfs = [&](auto&self,TreeNode* node,int dpth =0) ->void{
            if(node == nullptr)return ;
            ans = std::max(ans,dpth);
            self(self,node->left,dpth+1);
            self(self,node->right,dpth+1);
        };
        dfs(dfs,root);
        return ans+1;
    }
};