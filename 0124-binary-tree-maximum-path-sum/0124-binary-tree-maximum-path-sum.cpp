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
    int maxPathSum(TreeNode* root) {
        int ans = -111111111;
        auto dfs =[&](auto&self,TreeNode*node)->int{
            if(node == nullptr)return -10000000;
            int left = self(self,node->left);
            int right = self(self,node->right);
            // ans = max({ans,left,right,left+right});
            // cout<<left<<" "<<right<< " "<<node->val<<"\n";
            // left+=
            ans = max({ans,left+node->val,right+node->val,node->val+left+right,node->val});
            return max({left+node->val,right+node->val,node->val});
            // return ans;
        };
        dfs(dfs,root);
        return ans;
    }
};