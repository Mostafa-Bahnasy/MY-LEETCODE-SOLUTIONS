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
    bool hasPathSum(TreeNode* root, int targetSum) {
        auto dfs = [&](auto&self,TreeNode* node,int sum = 0)->bool{
            if(node == nullptr)
                return false;
            sum+=node->val;
            if(node->left==nullptr&&node->right==nullptr&& sum == targetSum)return true;
            return (self(self,node->left,sum) |self(self,node->right,sum));
            
        };
        return dfs(dfs,root);
    }
};